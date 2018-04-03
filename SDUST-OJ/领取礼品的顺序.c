#include <cstdio>
#include <cstdlib>
#define MAXSIZE 1000
typedef struct
{
    int *base;
    int front;
    int rear;
}SqQueue;

//初始化
int Init(SqQueue& Q)
{
    Q.base = new int[MAXSIZE];
    if(!Q.base)  return -1;
    Q.front = Q.rear = 0;
    return 1;
}

//加入
int QueueLen(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int EnQueue(SqQueue &Q, int e)
{
    if((Q.rear + 1) % MAXSIZE == Q.front)
        return -1;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return 1;
}

//删除
int DeQueue(SqQueue &Q, int &e)
{
    if(Q.front == Q.rear)
        return -1;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return 1;
}

//取队首元素
int GetHead(SqQueue &Q)
{
    if(Q.front != Q.rear)
        return Q.base[Q.front];
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        int n,k;
        sacnf("%d%d", &n, &k);
        for(int j = 0; j < n; j++){
            printf("Case #%d:", i);
        }
    }
}
