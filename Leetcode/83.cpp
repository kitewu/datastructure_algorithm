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
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p1 = head, *p2 = head->next;
        while(p2 != NULL) {
            if(p2->val != p1->val) {
                p1->next = p2;
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        p1->next = NULL;
        return head;
    }
};

int main() {
    Solution s;
    s.deleteDuplicates(NULL);
}
