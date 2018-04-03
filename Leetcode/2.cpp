#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode *head = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *p3 = head;
        while(p1 != NULL && p2 != NULL) {
            flag += p1->val + p2->val;
            p1 = p1->next;
            p2 = p2->next;
            p3->next = new ListNode(flag % 10);
            p3 = p3->next;
            flag /= 10;
        }
        while(p1 != NULL) {
            flag += p1->val;
            p1 = p1->next;
            p3->next = new ListNode((p1->val + flag) % 10);
            p3 = p3->next;
            flag /= 10;
        }
        while(p2 != NULL) {
            flag += p2->val;
            p2 = p2->next;
            p3->next = new ListNode(flag % 10);
            p3 = p3->next;
            flag /= 10;
        }
        if(flag > 0)
            p3->next = new ListNode(1);

        return head->next;
    }
};

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        int flag = 0;
//        ListNode *head = new ListNode(0);
//        ListNode *p1 = l1, *p2 = l2, *p3 = head;
//        while(p1 != NULL || p2 != NULL){
//            if(p1 != NULL){
//                flag += p1->val;
//                p1 = p1->next;
//            }
//            if(p2 != NULL){
//                flag += p2->val;
//                p2 = p2->next;
//            }
//            p3->next = new ListNode(flag % 10);
//            p3 = p3->next;
//            flag /= 10;
//        }
//        if(flag == 1)
//            p3->next = new ListNode(1);
//        return head->next;
//    }
//};

int main() {
}
