#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
//    ListNode* reverseList(ListNode* head) {
//        if(NULL == head)
//            return head;
//        ListNode* h = new ListNode(0);
//        h->next = NULL;
//        ListNode* p = head;
//        ListNode* t;
//        while(p){
//            t = p->next;
//            p->next = h->next;
//            h->next = p;
//            p = t;
//        }
//        return h->next;
//    }

//    ListNode* reverseList(ListNode* head) {
//        if (head == NULL || head->next == NULL)
//            return head;
//        ListNode* p = head->next;
//        head->next = NULL;
//        ListNode* newHead = reverseList(p);
//        p->next = head;
//        return newHead;
//    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* p = head;
        ListNode* q = p->next;
        p->next = NULL;

        while (q != NULL) {
            ListNode* t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};

int main() {
}
