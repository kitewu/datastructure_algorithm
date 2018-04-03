#include<iostream>
using namespace std;

typedef struct ListNode {
    int value;
    ListNode* next;
    ListNode(int v):value(v), next(NULL) {}
}*List;

void Show(ListNode* L1, ListNode* L2) {
    if(NULL == L1 || NULL == L2)
        return;
    List p1=L1, p2=L2;
    while(p1 && p2) {
        if(p1->value == p2->value) {
            cout << p1->value << " ";
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1->value < p2->value)
            p1 = p1->next;
        else
            p2 = p2->next;
    }
}

int main() {
    return 0;
}
