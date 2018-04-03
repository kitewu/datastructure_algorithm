#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return true;

        ListNode *p_fast = head, *p_slow = head;
        while(p_fast && p_fast->next) {
            p_fast = p_fast->next->next;
            p_slow = p_slow->next;
        }

        ListNode *p = p_slow, *q = p->next, *t;
        p->next = NULL;
        while (q) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }

        ListNode* p1 = head;
        while(p){
            if(p->val != p1->val)
                return false;
            p = p->next;
            p1 = p1->next;
        }
        return true;
    }
};

int main() {
    return 0;
}
