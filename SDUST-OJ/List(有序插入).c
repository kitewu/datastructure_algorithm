#include<stdio.h>
#define MAX_SIZE 100
typedef int value;
//插入有序
typedef struct
{
    value * elem;
    int len;
} List;

int InitList(List*);//初始化
void Print(List);//遍历
int Insert(List*, value);//添加
int Delete(List*, int);//删除
int Merge(List, List, List*);//有序合并

int main()
{
    List list;
    List list1;
    List list2;
    InitList(&list);
    Insert(&list, 4);
    Insert(&list, 2);
    Insert(&list, 3);
    Insert(&list, 1);
    Insert(&list, 5);
    Print(list);
    InitList(&list1);
    Insert(&list1, 4);
    Insert(&list1, 2);
    Insert(&list1, 3);
    Insert(&list1, 1);
    Insert(&list1, 5);
    Print(list1);
 }

//初始化
int InitList(List* list)
{
    list->elem = (value *)malloc(MAX_SIZE);
    list->len = 0;
    if(!list->elem)
    {
        return 0;
    }
    return 1;
}

//遍历
void Print(List list)
{
    if(0 != list.len)
    {
        int i;
        for(i = 0; i < list.len; i++)
        {
            if(0 != i)
                printf(" ");
            printf("%d",list.elem[i]);
        }
        printf("\n");
    }
}

//有序插入
int Insert(List* list, value v)
{
    int i;
    if(list->len == 0)
        i = 1;
    else
    {
        for(i = 1; i <= list->len; i++)
        {
            if(v < list->elem[i - 1])
            {
                break;
            }
        }
    }
    if((i < 1) || (i > list->len + 1) || (list->len == MAX_SIZE))
        return 0;
    else
    {
        int j;
        for(j = list->len - 1; j >= i - 1; j--)
        {
            list->elem[j + 1] = list->elem[j];
        }
        list->elem[i - 1] = v;
        list->len++;
        return 1;
    }
}

//删除
int Delete(List* list, int i)
{
    if(i < 1 || i > list->len)
        return 0;
    else
    {
        int j;
        for(j = i; j < list->len; j++)
        {
            list->elem[j - 1] = list->elem[j];
        }
        list->len--;
        return 1;
    }
}
//void CreateList_C(List La, List Lb,List *Lc)
//{
//    int i=0,j=0,k=1;
//    Lc = (value*)malloc(MAX_SIZE);
//    LC->len = 0;
//
//}

