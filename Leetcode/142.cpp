#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(NULL == head)
            return NULL;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                ListNode *p = head;
                while(true) {
                    if(p == fast)
                        return fast;
                    p = p->next;
                    fast = fast->next;
                }
            }
        }
        return NULL;
    }
};

int main() {
}
