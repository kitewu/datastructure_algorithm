#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return head;
        ListNode *p1 = head, *p2 = head->next, *h = new ListNode(0);
        ListNode *p = h;
        int count = 1;
        while(p2 != NULL) {
            if(p2->val == p1->val) {
                p2 = p2->next;
                count++;
            } else {
                if(count == 1) {
                    p->next = p1;
                    p = p->next;
                }
                p1 = p2;
                p2 = p2->next;
                count = 1;
            }
        }
        if(count == 1) {
            p->next = p1;
            p = p->next;
        }
        p->next = NULL;
        return h->next;
    }
};

int main() {
    return 0;
}
