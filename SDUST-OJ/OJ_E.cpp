#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;
typedef struct BiNode{				//二叉链表定义
	int data;
	struct BiNode *firstchild,*nextsibling;
}Node, *Tree;

Node* queueTree[30010];

//初始化
void initTree(Tree &T, int num){
    memset(queueTree, 0, 30010 * sizeof(Node*));
    T = new Node;
    T->data = 0;
    T->firstchild = NULL;
    T->nextsibling = NULL;
}

//建立二叉树
void createTree(Tree &T, int p, int c){

    Node* tt = new Node;
    tt->data = c;
    tt->firstchild = NULL;
    tt->nextsibling = NULL;
    queueTree[c] = tt;

	if(T->firstchild == NULL){
        //构建根节点
        T->data = p;
        queueTree[p] = T;
        T->firstchild = tt;
    //    cout << "????????" << queueTree[p]->data << endl;
	}else{
	    Node* temp = queueTree[p];
        if(temp->firstchild == NULL){
            temp->firstchild = tt;
       //     cout << "+++++++" << temp->firstchild->data << endl;
        }else{
            temp = temp->firstchild;
            while(temp->nextsibling != NULL){
                temp = temp->nextsibling;
            }
            temp->nextsibling = tt;
        //    cout << "----" << temp->nextsibling->data << endl;
        }
	}
}

void show(Tree T){
    if(T){
        show(T->firstchild);
        cout << T->data << " ";
        show(T->nextsibling);
    }
}

//求树高
int treeHeight(Tree T){
    int height = 0;
    int top = -1;
    Tree p = T;
    while(p || top!=-1){
        while(p){
            top++;
            queueTree[top] = p;
            p = p->firstchild;
        }
        if(height<top)
            height = top;
        p = queueTree[top]->nextsibling;
        top--;
        if(top == -1) break;
    }
    return height + 1;
}

//求二叉树的深度
int depth(Tree T){
    if(T == NULL){
       return 0;
    }else{
        int m = depth(T->firstchild);
        int n = depth(T->nextsibling);
        if(m > n)
            return m + 1;
        else
            return n + 1;
    }
}

int main(){
    int num;
    while(scanf("%d", &num) != EOF){
        Tree T;
        initTree(T, num);
        num--;
        while(num--){
            int p, c;
            scanf("%d%d", &p, &c);
            createTree(T, p, c);
        }
        cout << treeHeight(T) << " " << depth(T) << endl;
    }
}



