//#include<cstdio>
//#include<cstring>
//using namespace std;
//
//int n, q;
//
//typedef struct BSTNode{
//    char data[40];
//    char name[100];
//    int c, r;
//    BSTNode *lch, *rch;
//} BSTNode, *BSTree;
//
////比较
//int compare(char* T, char* S){
//    int i = 5, j = 5;
//    while(T[i] != 0 && S[j] != 0){
//        if(T[i] == '-'){
//            i++;
//            continue;
//        }
//        if(S[j] == '-'){
//            j++;
//            continue;
//        }
//        if(T[i] > S[j]){
//            return 1;
//        }
//        else if(T[i] < S[j]){
//            return -1;
//        }
//        else if(T[i] == S[j]){
//            i++;
//            j++;
//        }
//    }
//    if(i == strlen(T) && j == strlen(S))
//        return 0;
//    else{
//        if(i < strlen(T))
//            return 1;
//        return -1;
//    }
//}
//
////递归查找
//BSTree SearchBST(BSTree T, char* key){
//    if((!T) || compare(T->data, key) == 0)
//        return T;
//    else if (compare(T->data, key) > 0)
//        return SearchBST(T->lch, key);
//    else if(compare(T->data, key) < 0)
//        return SearchBST(T->rch, key);
//}
//
////插入
//void InsertBST(BSTree &T, BSTree &S){
//    if(!T)
//        T = S;
//    else if (compare(T->data, S->data) > 0)
//        InsertBST(T->lch, S);
//    else if (compare(T->data, S->data) < 0)
//        InsertBST(T->rch, S);
//}
//
////创建
//void CreateBST(BSTree &T){
//    getchar();
//    while(n--){
//        BSTree S = new BSTNode;
//        S->lch = S->rch = NULL;
//        scanf("%s%s%d%d", S->data, S->name, &(S->r), &(S->c));
//        InsertBST(T, S);
//    }
//}
//
////操作
//void Operator(BSTree &T){
//    scanf("%d", &q);
//    getchar();
//    while(q--){
//        char t[40];
//        gets(t);
//        BSTree tt = SearchBST(T, t);
//        if(tt!=NULL)
//            printf("%s %d %d\n", tt->name, tt->r, tt->c);
//    }
//}
//
//int main(){
//    while(scanf("%d", &n) != EOF){
//        BSTree T = NULL;
//        CreateBST(T);
//        Operator(T);
//    }
//}

#include <cstdio>
#include <string>
#include <string.h>
#include <iostream>
#include<algorithm>
using namespace std;
const int maxn = 30001;
int num=0;
struct Book
{
    char id[60],s[60];
    int r,c;
}book[maxn];

int bsearch(int l, int r, char str[]) {
    int mid = (l + r) / 2;
    while (l < r) {
        if (strcmp(book[mid].id, str) == 0) {
            return mid;
        } else if (strcmp(book[mid].id, str) < 0) {
            l = mid + 1;
        } else {
            r = mid;
        }
        mid = (l + r) / 2;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s%s%d%d", book[num].id, book[num].s, &book[num].r, &book[num].c);
            num++;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(book[i].id>book[j].id)
                {
                    Book t;
                    t=book[i];
                    book[i]=book[j];
                    book[j]=t;
                }
            }
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            char str[60];
            scanf("%s",str);
            int x=bsearch(0,n-1,str);
            printf("%s %d %d\n",book[x].s, book[x].r, book[x].c);
        }
    }
}
