#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Print(long int *list, int len)
{
    int k;
    for(k = 0; k < len; k++){
        if(k != 0)
            printf(" ");
        printf("%ld",list[k]);
    }
    printf("\n");
}
//交集
void jiao(long int *list1, long int *list2, int len1, int len2)
{
    int x1 = 0;//相当于指针
    int x2 = 0;
    int len3 = 0;
    long int *list3;
    list3 = (long int*)malloc(len1 + len2 + 100);
    while(x1 < len1 && x2 < len2){
        if(list1[x1] < list2[x2])
            x1++;
        else if(list1[x1] == list2[x2]){
            list3[len3] = list1[x1];
            x1++, x2++, len3++;
        }
        else
            x2++;
    }
    Print(list3, len3);
}

//并集
void bing(long int *list1, long int *list2, int len1, int len2)
{
    int x1 = 0;//相当于指针
    int x2 = 0;
    int len3 = 0;
    long int *list3;
    list3 = (long int*)malloc(len1 + len2 + 100);
    while(x1 < len1 && x2 < len2){
        if(list1[x1] < list2[x2]){
            list3[len3] = list1[x1];
            x1++; len3++;
        }
        else if(list1[x1] == list2[x2]){
            list3[len3] = list1[x1];
            len3++; x1++; x2++;
        }else{
            list3[len3] = list2[x2];
            x2++; len3++;
        }
    }
    if(x1 == len1){
        int jj;
        for(jj = x2; jj < len2; jj++){
            list3[len3] = list2[jj];
            len3++;
        }
    }else{
        int jj;
        for(jj = x1; jj < len1; jj++){
            list3[len3] = list1[jj];
            len3++;
        }
    }
    Print(list3, len3);
}

//A - B && A + B
void ajianb(long int *list1, long int *list2, int len1, int len2)
{
    int x1 = 0;//相当于指针
    int x2 = 0;
    int len3 = 0;
    long int *list3;
    list3 = (long int*)malloc(len1 + len2 + 100);
    while(x1 < len1 && x2 < len2){
        if(list1[x1] < list2[x2]){
            list3[len3] = list1[x1];
            x1++;
            len3++;
        }
        else if(list1[x1] == list2[x2]){
            x1++;
            x2++;
        }
        else{
            x2++;
        }
    }
    if(len1 != x1){
        int jj;
        for(jj = x1; jj < len1; jj++){
            list3[len3] = list1[jj];
            len3++;
        }
    }
    Print(list3, len3);
}

int main()
{
    int N;
    scanf("%d",&N);
    long int *list1;
    long int *list2;
    long int *list3;
    int n;
    for(n = 1; n <= N; n++){
        int len1;//链表1的长
        scanf("%d",&len1);
        list1 = (long int*)malloc(len1 + 100);//申请空间
        int i;
        for(i = 0; i < len1; i++){
            scanf("%ld",&list1[i]);
        }
        int len2;//链表2的长
        scanf("%d",&len2);
        list2 = (long int*)malloc(len2 + 100);//申请空间
        int j;
        for(j = 0; j < len2; j++){
            scanf("%ld",&list2[j]);
        }
        printf("Case #%d:\n",n);
        jiao(list1,list2,len1,len2);
        bing(list1,list2,len1,len2);
        ajianb(list1,list2,len1,len2);
        ajianb(list2,list1,len2,len1);
        free(list1);
        free(list2);
        free(list3);
    }
}
