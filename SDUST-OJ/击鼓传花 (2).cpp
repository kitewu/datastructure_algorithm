#include<iostream>
#include<string>
using namespace std;
int length = 0;
typedef struct LNode {
	int data; //结点的数据域
	struct LNode *next; //结点的指针域
	int pos;
} LNode, *List; //LinkList为指向结构体LNode的指针类型

void ListInsert(List &L, int e, List &pp) //将e插入到List中
{
    List node = new LNode;
    node->data = e;
    if(L == NULL){
        L = node;
        node->next = L;
        length++;
        node->pos = length;
    }else{
        pp->next = node;
        node->next = L;
        node->pos = node->pos + 1;
        length++;
        node->pos = length;
    }
    pp = node;

}

void ListOutput(List L) //输出List
{
	List p = L;
	while (p->next != L) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
}

int main() {
	int N;
    cin >> N;
    for(int xx = 1; xx <= N; xx++){
        length = 0;
        cout << "Case #" << xx << ":" << endl;
        List li = NULL;
        List pp = NULL;
        int begin;
        int n;
        cin >> n;
        while(n--){
            int t;
            cin >> t;
            ListInsert(li, t, pp);
        }
        begin = li->data;
        while(length > 1){
            if(begin >= length){
                 begin = (begin-1) % length + 1;
            }
            for(int i = 0; i < begin  - 1; i++){
                li = li->next;
            }
            begin = (li->next->next)->data;
            if(length == 2){
                cout << (li->next)->pos;
            }else{
                cout << (li->next)->pos << " ";
            }
            List t = li->next;
            li->next = t->next;
            li = li->next;
            delete t;
            length--;
        }
        cout << endl;
    }
}
