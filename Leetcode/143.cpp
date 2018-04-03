#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return;

        ///找到中间节点
        ListNode *p_fast = head->next, *p_slow = head;
        while(p_fast && p_fast->next) {
            p_fast = p_fast->next->next;
            p_slow = p_slow->next;
        }

        ///反转
        ListNode *p = p_slow->next, *q = p->next, *t;
        p_slow->next = NULL;
        p->next = NULL;
        while (q) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }

        ListNode *ptr = head;
        while(p){
            ListNode *temp = p->next;
            p->next = ptr->next;
            ptr->next = p;
            ptr = ptr->next->next;
            p = temp;
        }
    }
};

int main() {
    int n = 4;
    ListNode* h = new ListNode(1);
    ListNode* p = h;
    for(int i=2; i<=n; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution s;
    s.reorderList(h);
}
