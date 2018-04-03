#include<cstdio>
//交集
typedef struct
{
    long int *elem;
    int len;
}List;

//初始化
void Init(List &list, int len)
{
    list.elem = new long int[len + 10];
    list.len = 0;
}
//插入
void insert(List &list, long int value)
{
    list.elem[list.len] = value;
    list.len++;
}

void Print(List &list)
{
    int k;
    for(k = 0; k < list.len; k++){
        if(k != 0)
            printf(" ");
        printf("%ld",list.elem[k]);
    }
    printf("\n");
}
//交集
void jiao(List &list1, List &list2)
{
    List list3;
    Init(list3, list1.len + list2.len);
    int x1 = 0;//相当于指针
    int x2 = 0;
    while(x1 < list1.len && x2 < list2.len){
        if(list1.elem[x1] < list2.elem[x2])
            x1++;
        else if(list1.elem[x1] == list2.elem[x2]){
            insert(list3, list1.elem[x1]);
            x1++; x2++;
        }
        else
            x2++;
    }
    Print(list3);
    delete list3.elem;
    list3.len = 0;
}

//并集
void bing(List &list1, List &list2)
{
    List list3;
    Init(list3, list1.len + list2.len);
    int x1 = 0;//相当于指针
    int x2 = 0;
    while(x1 < list1.len && x2 < list2.len){
        if(list1.elem[x1] < list2.elem[x2]){
            insert(list3, list1.elem[x1]);
            x1++;
        }
        else if(list1.elem[x1] == list2.elem[x2]){
            insert(list3, list1.elem[x1]);
            x1++; x2++;
        }else{
            insert(list3, list2.elem[x2]);
            x2++;
        }
    }
    if(x1 == list1.len){
        int jj;
        for(jj = x2; jj < list2.len; jj++){
            insert(list3, list2.elem[jj]);
        }
    }else{
        int jj;
        for(jj = x1; jj < list1.len; jj++){
            insert(list3, list1.elem[jj]);
        }
    }
    Print(list3);
    delete list3.elem;
    list3.len = 0;
}

//A - B && A + B
void ajianb(List &list1, List &list2)
{
    List list3;
    Init(list3, list1.len + list2.len + 10);
    int x1 = 0;//相当于指针
    int x2 = 0;
    while(x1 < list1.len && x2 < list2.len){
        if(list1.elem[x1] < list2.elem[x2]){
            insert(list3, list1.elem[x1]);
            x1++;
        }
        else if(list1.elem[x1] == list2.elem[x2]){
            x1++; x2++;
        }
        else{
            x2++;
        }
    }
    if(list1.len != x1){
        int jj;
        for(jj = x1; jj < list1.len; jj++){
            insert(list3, list1.elem[jj]);
        }
    }
    Print(list3);
    delete list3.elem;
    list3.len = 0;
}

int main()
{
    int n, N;
    scanf("%d",&N);
    for(n = 1; n <= N; n++){
        List list1;
        List list2;

        int len, i;

        scanf("%d",&len);
        Init(list1, len);
        for(i = 0; i < len; i++){
            long int value;
            scanf("%ld",&value);
            insert(list1, value);
        }

        scanf("%ld",&len);
        Init(list2, len);
        for(i = 0; i < len; i++){
            long int value;
            scanf("%ld",&value);
            insert(list2, value);
        }

        printf("Case #%d:\n",n);
        jiao(list1,list2);
        bing(list1,list2);
        ajianb(list1,list2);
        ajianb(list2,list1);
        delete list1.elem;
        delete list2.elem;
    }
}
