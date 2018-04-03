#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef struct Node{
    int data;
    Node* lch, *rch;
}Node, *Tree;

Node *queueTree[30010];

//初始化
void Init(Node **nodes, int *calroot, int num){
    memset(nodes, 0, num * sizeof(Node*));
    memset(calroot, 0, (num) * sizeof(int));
}

//建立数组指针二叉树
void createTree(Node **nodes, int *calroot){
    int pa, ch;
    scanf("%d%d", &pa, &ch);
    Node* parent;
    Node* child;
    if(nodes[pa] == 0){
        parent = new Node;
        parent->data = pa;
        parent->lch = NULL;
        parent->rch = NULL;
        nodes[pa] = parent;
    }else
        parent = nodes[pa];

    if(nodes[ch] == 0){
        child = new Node;
        child->data = ch;
        child->lch = NULL;
        child->rch = NULL;
        nodes[ch] = child;
    }else
        child = nodes[ch];

    if(parent->lch == NULL){
        parent->lch = child;
    }else{
        Node* temp = parent->lch;
        while(temp->rch != NULL){
            temp = temp->rch;
        }
        temp->rch = child;
    }
    calroot[ch]++;
}

//获得根节点
int getRoot(int* calroot, int num){
    for(int i = 1; i < num; i++){
        if(calroot[i] == 0){
            return i;
        }
    }
}

//求二叉树的深度
int depth(Tree T){
    if(T == NULL){
       return 0;
    }else{
        int m = depth(T->lch);
        int n = depth(T->rch);
        if(m > n)
            return m + 1;
        else
            return n + 1;
    }
}

//求树深
int treeHeight(Tree T){
    int height = 0;
    int top = -1;
    Tree p = T;
    while(p||top!=-1){
        while(p){
            top++;
            queueTree[top] = p;
            p = p->lch;
        }
        if(height<top)
            height = top;
        p = queueTree[top]->rch;
        top--;
        if(top == -1) break;
    }
    return height + 1;
}

int main()
{
    int num;
    while(scanf("%d", &num) != EOF){
        num++;
        Node* nodes[num];
        int calroot[num];
        Init(nodes, calroot, num);
        for(int i = 0; i < num - 2; i++)
            createTree(nodes, calroot);
        int root = getRoot(calroot, num);
        printf("%d %d\n", treeHeight(nodes[root]), depth(nodes[root]));
    }
}
