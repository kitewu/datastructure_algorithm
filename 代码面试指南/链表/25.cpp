#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1 || NULL==head || NULL == head->next)
            return head;
        ListNode* p = head;
        int i;
        for(i=0; i<k && p; i++, p=p->next);
        if(NULL == p && i<k) { ///长度不够直接返回
            return head;
        } else {
            ListNode *p1 = head;
            ListNode *p2 = head->next;
            while(p2 != p) {
                ListNode *t = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = t;
            }
            head->next = reverseKGroup(p, k);
            head = p1;
        }
        return head;
    }
};

int main() {
    ListNode *h = new ListNode(1);
    ListNode *p = h;
    for(int i=2; i<=5; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution s;
    ListNode *t = s.reverseKGroup(h, 2);
    while(t) {
        cout << t->val << " ";
        t = t->next;
    }
}
