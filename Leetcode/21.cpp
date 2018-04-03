#include<cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode(0);
        ListNode *p3 = newList;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                p3->next = l2;
                l2 = l2->next;
            } else {
                p3->next = l1;
                l1 = l1->next;
            }
            p3 = p3->next;
        }
        if(l1)
            p3->next = l1;
        else if(l2)
            p3->next = l2;
        return newList->next;
    }
};

int main() {


}
