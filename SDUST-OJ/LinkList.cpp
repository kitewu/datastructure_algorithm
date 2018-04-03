#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int Elemtype;
typedef struct LNode
{
    Elemtype data;
    struct LNode* next;
}LNode, *LinkList;

int Init(LinkList L)
{
    L = (LNode*)malloc(sizeof(LNode) + 10);
    L->next = NULL;
    return 1;
}

//Ç°²å·¨
int insertNode(LinkList L, int i, Elemtype e)
{
    LNode* p;
    p = L;
    int j = 0;
    while(p && (j < i - 1)){
        p = p->next;
        ++j;
    }
    if(!p || (j > i - 1)){
        return 0;
    }
    LNode *s;
    s = (LNode*)malloc(sizeof(LNode) + 10);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

//É¾³ý
int deleteNode(LinkList L, int i)
{
    LinkList p;
    p = L;
    int j = 0;
    while(p->next && (j < i - 1)){
        p = p->next;
        ++j;
    }
    if(!(p->next) || (j > i - 1)){
        return 0;
    }
    LNode* q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}

void print(LinkList L)
{
    LNode* p;
    p = L;
    while(p->next){
        p = p->next;
        printf("%d ",p->data);
    }
    printf(" ");
}

int main()
{
    LinkList L;
    Init(L);
    for(int i = 1; i <= 5; i++)
        insertNode(L,i,i);
    print(L);
}
