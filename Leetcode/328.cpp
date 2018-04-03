#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(NULL == head || head->next == NULL)
            return head;
        ListNode *h1 = head, *h2 = head->next;
        ListNode *p1 = h1, *p2 = h2, *p = head->next->next;
        bool flag = true;
        while(p) {
            if(flag) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
            flag = !flag;
        }
        p2->next = NULL;
        p1->next = h2;
        return h1;
    }
};

int main() {
}
