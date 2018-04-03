#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode * node = head;
        while (node != NULL) {
            node = node->next;
            len++;
        }
        return buildTree(head, 0, len-1);
    }

    TreeNode *buildTree(ListNode *&node, int start, int end) {
        if (start > end)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode *left = buildTree(node, start, mid-1);
        TreeNode *root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        root->right = buildTree(node, mid+1, end);
        return root;
    }



//    TreeNode* sortedListToBST(ListNode* head) {
//        if(NULL == head) return NULL;
//        vector<TreeNode*> vv;
//        while(head) {
//            vv.push_back(new TreeNode(head->val));
//            head = head->next;
//        }
//        return buildBST(vv, 0, vv.size());
//    }
//
//    TreeNode* buildBST(vector<TreeNode*> &vv, int begin, int end) {
//        if(begin >= end)
//            return NULL;
//        int mid = (end+begin)/2;
//        TreeNode* root = vv[mid];
//        root->left = buildBST(vv, begin, mid);
//        root->right = buildBST(vv, mid+1, end);
//        return root;
//    }
//
//    void showList(ListNode* head) {
//        ListNode* p = head;
//        while(p) {
//            cout << p->val << " ";
//            p = p->next;
//        }
//        cout << endl;
//    }
//
//    void show(TreeNode* root) {
//        if(root == NULL) {
//            return;
//        }
//        show(root->left);
//        cout << root->val << " ";
//        show(root->right);
//    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(0);
    ListNode* p = head;
    for(int i=1; i<10; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    p->next = NULL;
    s.sortedListToBST(head);
    return 0;
}
