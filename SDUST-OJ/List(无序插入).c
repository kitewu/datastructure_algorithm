#include<stdio.h>
#define MAX_SIZE 100
typedef int value;
//插入无序
typedef struct
{
    value * elem;
    int len;
} List;

int InitList(List*);//初始化
void Print(List);//遍历
int Insert(List*, int, value);//插入
int Delete(List*, int);//删除
int Sort(List*);//排序

int main()
{
    List list;
    InitList(&list);
    int i;
    for(i = 1; i <= 10; i++)
        Insert(&list, i, 10 - i);
    Print(list);
    Sort(&list);
    Print(list);
}

int InitList(List* list)
{
    list->elem = (value *)malloc(MAX_SIZE);
    list->len = 0;
    if(!list->elem){
        return 0;
    }
    return 1;
}

void Print(List list)
{
    if(0 != list.len){
        int i;
        for(i = 0; i < list.len; i++){
            if(0 != i)
                printf(" ");
            printf("%d",list.elem[i]);
        }
        printf("\n");
    }
}

int Insert(List* list, int i, value v)
{
    if((i < 1) || (i > list->len + 1) || (list->len == MAX_SIZE))
        return 0;
    else{
        int j;
        for(j = list->len - 1; j >= i - 1; j--){
            list->elem[j + 1] = list->elem[j];
        }
        list->elem[i - 1] = v;
        list->len++;
        return 1;
    }
}

int Delete(List* list, int i)
{
    if(i < 1 || i > list->len)
        return 0;
    else{
        int j;
        for(j = i; j < list->len; j++){
            list->elem[j - 1] = list->elem[j];
        }
        list->len--;
        return 1;
    }
}

int Sort(List* list)
{
    if(list->len > 0){
        int i;
        int j;
        for(i = 0; i < list->len - 1;i++){
            for(j = 0; j < list->len - i; j++){
                if(list->elem[j] > list->elem[j + 1]){
                    list->elem[j] = list->elem[j] ^ list->elem[j + 1];
                    list->elem[j + 1] = list->elem[j] ^ list->elem[j + 1];
                    list->elem[j] = list->elem[j] ^ list->elem[j + 1];
                }
            }
        }
        return 1;
    }
    return 0;
}
