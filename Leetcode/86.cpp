#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
        	return head;
        ListNode* less = new ListNode(0);
        ListNode* more = new ListNode(0);
        ListNode* less_p = less, *more_p = more;
        while(head != NULL){
        	if(head->val < x){
        		less_p->next = head; 
        		less_p = less_p->next;
			}else{
				more_p->next = head; 
        		more_p = more_p->next;
			}
			head = head->next;
		}
		more_p->next = NULL;
		less_p->next = more->next;
		ListNode* p= less->next;
		return less->next;
    }
};

int main(){
	ListNode* head = new ListNode(2);
	head->next=new ListNode(1); 
	Solution s;
	s.partition(head, 2);
}
