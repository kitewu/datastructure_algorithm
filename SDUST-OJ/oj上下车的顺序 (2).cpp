#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef struct
{
    int *base;
    int *top;
    int stacksize;
}SqStack;

int InitStack(SqStack &S)
{
    S.base=new int[MAXSIZE];
    if(!S.base) return -1;
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return 1;
}

int Push(SqStack &S,int e)
{
    if(S.top-S.base==S.stacksize) return 0;
    *S.top++=e;
    return 1;
}

int Pop(SqStack &S,int &e)
{
    if(S.top==S.base) return 0;
    e=*--S.top;
    return 1;
}

int GetTop(SqStack &S)
{
    if(S.top!=S.base)
        return *(S.top-1);
}

int main()
{
    int sum,i;
    scanf("%d",&sum);
    for(i=1;i<=sum;i++)
    {
        SqStack S;
        InitStack(S);
        int n,c;
        printf("Case #%d:\n",i);
        scanf("%d%d",&n,&c);
        S.stacksize=c;
        int j,a;
        for(j=1;j<=n;j++)
        {
            int m;
            scanf("%d",&m);
            if(m>0)
            {
                int k;
                for(k=1;k<=m;k++)
                {
                    scanf("%d",&a);
                    Push(S,a);
                }
            }
            if(m==0)
            {
                scanf("%d",&a);
                int l;
                for(l=1;l<=a;l++)
                {
                    printf("%d",GetTop(S));
                    if(l!=a)
                        printf(" ");
                    int e;
                    Pop(S,e);
                }
                printf("\n");
            }
        }
    }
}
