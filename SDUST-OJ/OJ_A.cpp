#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<stack>
#define MAX 26
using namespace std;
typedef struct Node{
    int weight;
    char data;
    Node* parent;
    Node* lch;
    Node* rch;
}Node, *Tree;

void Init(Node* *array, Node* *HuffmanCode, string *code){
    memset(array, 0, MAX * sizeof(Node*));
    memset(HuffmanCode, 0, MAX * sizeof(Node*));
    for(int i = 0 ;i < MAX; i++){
        code[i].clear();
    }
}

//构建数组
void createArray(Node* *array, Node* *HuffmanCode, string str, int &sum){
    for(int i = 0; i < str.length(); i++){
        if(array[str[i] - 'A'] == 0){
            Node *t = new Node;
            t->data = str[i];
            t->weight = 1;
            t->lch = NULL;
            t->rch = NULL;
            t->parent = NULL;
            array[str[i] - 'A'] = t;
            HuffmanCode[str[i] - 'A'] = t;
            sum++;
        }else{
            array[str[i] - 'A']->weight++;
        }
    }
}

//复制节点
void copy(Node* &a, Node* &b){
    a->data = b->data;
    a->weight = b->weight;
    a->lch = b->lch;
    a->rch = b->rch;
    a->parent = b->parent;
}

//选择节点
void selete(Node* &min, Node* &mid, Node* *array){
    int flagmin, flagmid;
    min = new Node;
    min->weight = 1010;
    min->data = -1;
    mid = new Node;
    mid->weight = 1010;
    mid->data = -1;
    for(int i = 0; i < 26; i++){
        if(array[i] != 0){
            if((array[i]->weight < min->weight) || ((array[i]->weight == min->weight) && (array[i]->data > min->data))){
                copy(mid, min);
                flagmid = flagmin;
                copy(min, array[i]);
                flagmin = i;
                continue;
            }
            if((array[i]->weight < mid->weight) || ((array[i]->weight == mid->weight) && (array[i]->data > mid->data))){
                copy(mid, array[i]);
                flagmid = i;
            }
        }
    }
    delete min, mid;
    min = array[flagmin];
    mid = array[flagmid];
    array[flagmin] = 0;
    array[flagmid] = 0;
    if(min->data > mid->data){
        Node* temp = min;
        min = mid;
        mid = temp;
    }
}

//构建哈夫曼树
void createTree(Node* *array, int &root, int &sum){
    Node* node;
    sum--;
    while(sum--){
        Node* min;
        Node* mid;
        selete(min, mid, array);
        node = new Node;
        node->weight = min->weight + mid->weight;
        node->data = min->data;
        node->lch = min;
        node->rch = mid;
        min->parent = node;
        mid->parent = node;
        array[node->data - 'A'] = node;
    }
    root = node->data - 'A';
}

//构造哈夫曼编码
void createHuffmanCode(Node* *HuffmanCode, string *code){
    string t = "";
    for(int i = 0; i < 26; i++){
        if(HuffmanCode[i] != 0){
            if(HuffmanCode[i]->parent == NULL){
                t = '0' + t;
                code[i] = t;
            }else{
                Node* par = HuffmanCode[i]->parent;
                Node* chi = HuffmanCode[i];
                while(par){
                    if(chi == par->lch)
                        t = '0' + t;
                    if(chi == par->rch)
                        t = '1' + t;
                    par = par->parent;
                    chi = chi->parent;
                }
                code[i] = t;
            }

            cout << HuffmanCode[i]->data << ": " << code[i] << endl;
            t.clear();
        }
    }
}
//
//void deleteNode(Node* *HuffmanCode){
//    for(int i = 0; i < 26; i++){
//        if(HuffmanCode[i] != 0)
//            delete HuffmanCode[i];
//    }
//}

void show(char *str, string *code){
    int length = 0;
    for(int i = 0; i < str.length(); i++){
        length += code[str[i] - 'A'].length();
    }
    if(length < 50){
        printf("%d ", length);
        for(int i = 0; i < str.length(); i++){
            cout << code[str[i] - 'A'];
        }
        printf("\n");
    }
}

stack<Node*> st;
void deleteTree(Node* T){
    if(T == NULL)
        return;
    else{
        st.push(T);
        deleteTree(T->rch);
        deleteTree(T->lch);
    }
}

int main()
{
    char str[1000];
    int N = 1;
    while(gets(str) != EOF){
        Node* array[MAX];
        Node* HuffmanCode[MAX];
        string code[MAX];
        int root = 0;
        int sum = 0;

        printf("Case #%d:\n", N++);
        Init(array, HuffmanCode, code);
        createArray(array, HuffmanCode, str, sum);
        createTree(array, root, sum);
        createHuffmanCode(HuffmanCode, code);
        show(str, code);
        deleteTree(array[root]);
        while(!st.empty()){
            Node* t = st.top();
            st.pop();
            delete t;
        }
    }
}

