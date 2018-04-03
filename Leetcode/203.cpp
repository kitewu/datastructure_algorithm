#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(NULL == head)
            return head;
        ListNode* H = new ListNode(0);
        H->next = head;
        ListNode* last = H;
        while(head) {
            if(head->val == val) {
                last->next = head->next;
            } else {
                last = last->next;
            }
            head = head->next;
        }
        return H->next;
    }
};

int main() {
    return 0;
}
