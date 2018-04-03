#include<iostream>
#include<cstdio>
using namespace std;
typedef int ElemType;
struct LNode
{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode *LinkList; /* 另一种定义LinkList的方法 */

int InitList_CL(LinkList L)
{
    L=(LinkList)malloc(sizeof(struct LNode));
    if(!L) /* 存储分配失败 */
        exit(-1);
    (L)->next=L; /* 指针域指向头结点 */
    return 1;
}
int ClearList_CL(LinkList *L) /* 改变L */
{
    /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
    LinkList p,q;
    *L=(*L)->next; /* L指向头结点 */
    p=(*L)->next; /* p指向第一个结点 */
    while(p!=*L) /* 没到表尾 */
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=*L; /* 头结点指针域指向自身 */
    return 1;
}
int ListEmpty_CL(LinkList L)
{
    if(L->next==L) /* 空 */
        return true;
    else
        return false;
}
int ListLength_CL(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向头结点 */
    while(p!=L) /* 没到表尾 */
    {
        i++;
        p=p->next;
    }
    return i;
}
int GetElem_CL(LinkList L,int i,ElemType *e)
{
    /* 当第i个元素存在时,其值赋给e并返回1,否则返回-1 */
    int j=1; /* 初始化,j为计数器 */
    LinkList p=L->next->next; /* p指向第一个结点 */
    if(i<=0||i>ListLength_CL(L)) /* 第i个元素不存在 */
        return -1;
    while(j<i)
    {
        /* 顺指针向后查找,直到p指向第i个元素 */
        p=p->next;
        j++;
    }
    *e=p->data; /* 取第i个元素 */
    return 1;
}
int LocateElem_CL(LinkList L,ElemType e,int(*compare)(ElemType,ElemType))
{
    /* 初始条件：线性表L已存在，compare()是数据元素判定函数 */
    /* 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。 */
    /*      若这样的数据元素不存在，则返回值为0 */
    int i=0;
    LinkList p=L->next->next; /* p指向第一个结点 */
    while(p!=L->next)
    {
        i++;
        if(compare(p->data,e)) /* 满足关系 */
            return i;
        p=p->next;
    }
    return 0;
}
int PriorElem_CL(LinkList L,ElemType cur_e,ElemType *pre_e)
{
    /* 初始条件：线性表L已存在 */
    /* 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， */
    /*      否则操作失败，pre_e无定义 */
    LinkList q,p=L->next->next; /* p指向第一个结点 */
    q=p->next;
    while(q!=L->next) /* p没到表尾 */
    {
        if(q->data==cur_e)
        {
            *pre_e=p->data;
            return true;
        }
        p=q;
        q=q->next;
    }
    return false;
}
int NextElem_CL(LinkList L,ElemType cur_e,ElemType *next_e)
{
    /* 初始条件：线性表L已存在 */
    /* 操作结果：若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继， */
    /*      否则操作失败，next_e无定义 */
    LinkList p=L->next->next; /* p指向第一个结点 */
    while(p!=L) /* p没到表尾 */
    {
        if(p->data==cur_e)
        {
            *next_e=p->next->data;
            return true;
        }
        p=p->next;
    }
    return false;
}
int ListInsert_CL(LinkList *L,int i,ElemType e) /* 改变L */
{
    /* 在L的第i个位置之前插入元素e */
    LinkList p=(*L)->next,s; /* p指向头结点 */
    int j=0;
    if(i<=0||i>ListLength_CL(*L)+1) /* 无法在第i个元素之前插入 */
        return -1;
    while(j<i-1) /* 寻找第i-1个结点 */
    {
        p=p->next;
        j++;
    }
    s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
    s->data=e; /* 插入L中 */
    s->next=p->next;
    p->next=s;
    if(p==*L) /* 改变尾结点 */
        *L=s;
    return 1;
}
int ListDelete_CL(LinkList *L,int i,ElemType *e) /* 改变L */
{
    /* 删除L的第i个元素,并由e返回其值 */
    LinkList p=(*L)->next,q; /* p指向头结点 */
    int j=0;
    if(i<=0||i>ListLength_CL(*L)) /* 第i个元素不存在 */
        return -1;
    while(j<i-1) /* 寻找第i-1个结点 */
    {
        p=p->next;
        j++;
    }
    q=p->next; /* q指向待删除结点 */
    p->next=q->next;
    *e=q->data;
    if(*L==q) /* 删除的是表尾元素 */
        *L=p;
    free(q); /* 释放待删除结点 */
    return 1;
}

void visit(ElemType c)
{
    printf("%d ",c);
}
int main()
{
    LinkList L;
    InitList_CL(L);
    ListInsert_CL()
}
