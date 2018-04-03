#include<iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int v):value(v), next(NULL) {}
};

struct DoubleNode {
    int value;
    DoubleNode *next, *last;
    DoubleNode(int v) : value(v) {
        next = last = NULL;
    }
};

///双链表方法
DoubleNode* removeNthFromEndDouble(DoubleNode* head, int n) {
    if(NULL==head || n<1) return head;
    DoubleNode* p = head;
    while(p) {
        n--;
        p = p->next;
    }
    if(n == 0)
        return head->next;
    if(n < 0) {
        p = head;
        while(++n)
            p = p->next;
        p->next = p->next->next;
        p->next->next->last = p;
    }
    return head;
}

///单链表方法1
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(NULL==head || n<1) return head;
    ListNode* p = head;
    while(p) {
        n--;
        p = p->next;
    }
    if(n == 0)
        return head->next;
    if(n < 0) {
        p = head;
        while(++n)
            p = p->next;
        p->next = p->next->next;
    }
    return head;
}
///单链表方法2
ListNode* removeNthFromEnd1(ListNode* head, int n) {
    if(NULL==head || n<1) return head;
    ListNode *h = new ListNode(0);
    h->next = head;
    ListNode* p1 = h, *p2 = h;
    for(int i=0; i<n && p1; i++, p1 = p1->next);
    if(NULL == p1)
        return head;
    while(p1->next) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = p2->next->next;
    return h->next;
}


int main() {
    return 0;
}
