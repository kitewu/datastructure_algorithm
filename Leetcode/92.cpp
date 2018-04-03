#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n) return head;

        ListNode* h = new ListNode(0);///新的头
        h->next = head;
        ListNode *p = head, *pre = h;///开始反转的节点及前一个节点
        for(int i=1; i<m; i++){
            p = p->next;
            pre = pre->next;
        }

        ListNode *q = p->next, *tail = p, *t;
        int time = n - m;
        while (q != NULL) {
            if(time <= 0)
                break;
            t = q->next;
            q->next = p;
            p = q;
            q = t;
            --time;
        }
        pre->next = p;
        tail->next = q;
        return h->next;
    }
};

int main() {
    int n = 3;
    ListNode* h = new ListNode(1);
    ListNode* p = h;
    for(int i=2; i<=n; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution s;
    s.reverseBetween(h, 2, 3);
}

