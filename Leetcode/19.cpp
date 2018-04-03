#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode *p1 = head, *p2 = head;
        while(n--)
            p1 = p1->next;
        if(p1 == NULL){
            head = head->next;
            return head;
        }
        while(p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};

int main() {
    ListNode h1(1);
//    ListNode h2(2);
//    ListNode h3(3);
//    ListNode h4(4);
//    ListNode h5(5);
//    ListNode h6(6);
//    h1.next = &h2;
//    h2.next = &h3;
//    h3.next = &h4;
//    h4.next = &h5;
//    h5.next = &h6;
    Solution s;
    s.removeNthFromEnd(&h1, 1);
    ListNode *p = &h1;
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }
}
