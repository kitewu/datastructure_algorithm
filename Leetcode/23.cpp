#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct CompareListNode {
    bool operator()(const ListNode* p, const ListNode* q)const {
        return p->val > q->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0)
            return NULL;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> que;
        for(int i = 0; i < len; i++) {
            if(lists[i])
                que.push(lists[i]);
        }
        while(!que.empty()) {
            p->next = que.top();
            que.pop();
            p = p->next;
            if(p->next)
                que.push(p->next);
        }
        p->next = NULL;
        return head->next;
    }
};

int main() {
    ListNode* list = new ListNode(1);
    ListNode* list1 = new ListNode(0);
    vector<ListNode*> v;
    v.push_back(list);
    v.push_back(list1);
    Solution s;
    ListNode *head = s.mergeKLists(v);
    while(head != NULL) {
        cout << head->val << endl;
        head = head->next;
    }
}
