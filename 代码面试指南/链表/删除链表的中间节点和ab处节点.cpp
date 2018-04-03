#include<iostream>
#include<cmath>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int v):value(v), next(NULL) {}
};

///删除中间节点
ListNode* deleteMidNode(ListNode* head) {
    if(NULL == head || NULL == head->next) return head;
    ListNode *p_fast = head->next;
    ListNode *p_slow = head;
    while(p_fast && p_fast->next) {
        p_fast = p_fast->next->next;
        p_slow = p_slow->next;
    }
    cout << p_slow->value << endl;
    ///复制后一个节点的值的方式
    p_slow->value = p_slow->next->value;
    p_slow->next = p_slow->next->next;
    return head;
}

///删除链表第a/b处节点
ListNode* deleteABNode(ListNode* head, int a, int b) {
    if(NULL==head || a<1 || a>b) return head;
    ListNode* cur = head;
    int n = 0;
    while(cur) {
        n++;
        cur = cur->next;
    }
    n = ceil(a*1.0*n/b);
    if(n == 1)
        return head->next;
    cur = head;
    while(--n != 1) {
        cur = cur->next;
    }
    cout << cur->next->value << endl;
    cur->next = cur->next->next;
    return head;
}

int main() {
    ListNode *h = new ListNode(1);
    ListNode *p = h;
    for(int i=2; i<=7; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    deleteABNode(h, 1, 6);
   // deleteMidNode(h);
    return 0;
}
