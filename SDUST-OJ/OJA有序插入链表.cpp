#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode,*LinkList;
//初始化
void init(LinkList &list)
{
    list = new LNode;
    list->next = NULL;
}
//有序插入
void insert(LinkList &list, int v)
{
    LinkList pp = list;
    LinkList p = list->next;
    while(p != NULL)
    {
        if(p->data > v)
            break;
        else
        {
            p = p->next;
            pp = pp->next;
        }
    }
    LNode* node = (LinkList)malloc(sizeof(LNode));
    node->data = v;
    node->next = pp->next;
    pp->next = node;
}
void Jiao(LinkList L1,LinkList L2)
{
    int flag = 0;
    LinkList p1=L1->next,p2=L2->next;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data==p2->data)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p1->data);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data)
            p2=p2->next;
        else if(p1->data<p2->data)
            p1=p1->next;
    }
    printf("\n");
}

void Bing(LinkList L1,LinkList L2)
{
    int flag = 0;
    LinkList p1=L1->next,p2=L2->next;
    while(p1!=NULL || p2!=NULL)
    {
        if(p1==NULL)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p2->data);
            p2=p2->next;
        }
        else if(p2==NULL)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p1->data);
            p1=p1->next;
        }
        else if(p1->data==p2->data)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p1->data);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p2->data);
            p2=p2->next;
        }
        else if(p1->data<p2->data)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p1->data);
            p1=p1->next;
        }
    }
    printf("\n");
}

void Cha(LinkList L1,LinkList L2)
{
    int flag = 0;
    LinkList p1=L1->next,p2=L2->next;
    while(p1!=NULL || p2!=NULL)
    {
        if(p1==NULL)
        {
            break;
        }
        else if(p2==NULL)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p1->data);
            p1=p1->next;
        }
        else if(p1->data==p2->data)
        {
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data)
        {
            p2=p2->next;
        }
        else if(p1->data<p2->data)
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d",p1->data);
            p1=p1->next;
        }
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int L1,L2;
        scanf("%d",&L1);
        LinkList Head1;
        init(Head1);
        for(int j=0; j<L1; j++)
        {
            int x;
            scanf("%d",&x);
            insert(Head1,x);
        }
        scanf("%d",&L2);
        LinkList Head2;
        init(Head2);
        for(int j=0; j<L2; j++)
        {
            int x;
            scanf("%d",&x);
            insert(Head2,x);
        }
        printf("Case #%d:\n",i+1);
        Jiao(Head1,Head2);
        Bing(Head1,Head2);
        Cha(Head1,Head2);
        Cha(Head2,Head1);
    }
}
