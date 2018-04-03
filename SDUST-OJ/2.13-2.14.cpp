#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct DuLNode {
	char data; //数据域
	struct DuLNode *prior; //直接前驱
	struct DuLNode *next; //直接后继
} DuLNode, *DuLinkList;

int InitDuList_L(DuLinkList &L) {
	L = new DuLNode;
	L->next = NULL;
	L->prior = NULL;
	return 1;
}

int ListInsert_DuL(DuLinkList &p, char e) {
    DuLNode *node = new DuLNode;
    node->data = e;
    node->next = NULL;
    node->prior = p;
    p->next = node;
    p = node;
	return 1;
}

void print(DuLinkList L)
{
    DuLinkList p = L->next;
    while(p){
        cout << p->data << ",";
        p = p->next;
    }
}

void deleteList(DuLinkList L)
{
    DuLinkList p = L;
    while(L){
        p = L;
        L = L->next;
        delete p;
    }
}
int main()
{
    int N;
    cin >> N;
    getchar();
    while(N--){
        DuLinkList L;
        InitDuList_L(L);
        DuLinkList p = L;
        char str[110];
        while(gets(str)){
            if(str[0] == '#' && str[1] == '#'){
                goto loop;
            }
            else if(str[0] == '#' && str[1] == 'U'){
                if(p != L)
                    p = p->prior;
            }
            else if(str[0] == '#' && str[1] == 'R'){
                if(p->next != NULL)
                    p = p->next;
                DuLinkList t = L->next;
                while(t != p){
                    cout << t->data;
                    t = t->next;
                }
                cout << t->data << endl;
            }
            else{
                for(int i = 0; i < strlen(str); i++){
                    if(p->next != NULL){
                        p = p->next;
                        p->data = str[i];
                    }
                    else{
                        ListInsert_DuL(p ,str[i]);
                    }
                }
            }
        }
        loop:;
        deleteList(L);
    }
}
