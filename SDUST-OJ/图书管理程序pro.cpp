#include<cstdio>
#include<cstring>
#define MAX 30005
using namespace std;

int n, q;

typedef struct BSTNode{
    char data[40];
    char name[100];
    int c, r;
    BSTNode *lch, *rch;
} BSTNode, *BSTree;

//递归查找
BSTree SearchBST(BSTree T, char* key){
    if((!T) || strcmp(T->data, key) == 0)
        return T;
    else if (strcmp(T->data, key) > 0)
        return SearchBST(T->lch, key);
    else if(strcmp(T->data, key) < 0)
        return SearchBST(T->rch, key);
}

//插入
void InsertBST(BSTree &T, BSTree &S){
    if(!T)
        T = S;
    else if (strcmp(T->data, S->data) > 0)
        InsertBST(T->lch, S);
    else if (strcmp(T->data, S->data) < 0)
        InsertBST(T->rch, S);
}

//创建
void CreateBST(BSTree &T){
    getchar();
    while(n--){
        BSTree S = new BSTNode;
        S->lch = S->rch = NULL;
        scanf("%s%s%d%d", S->data, S->name, &(S->r), &(S->c));
        InsertBST(T, S);
    }
}

//操作
void Operator(BSTree &T){
    scanf("%d", &q);
    getchar();
    while(q--){
        char t[40];
        gets(t);
        BSTree tt = SearchBST(T, t);
        if(tt!=NULL)
            printf("%s %d %d\n", tt->name, tt->r, tt->c);
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        BSTree T = NULL;
        CreateBST(T);
        Operator(T);
    }
}
