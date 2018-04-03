#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
//    bool isSymmetric(TreeNode* root) {
//        if(!root)
//            return true;
//        return isSymmetric(root->left, root->right);
//    }
//
//    bool isSymmetric(TreeNode* p, TreeNode* q) {
//        if(p == NULL && q == NULL)
//            return true;
//        if(p == NULL || q == NULL)
//            return false;
//        return p->val == q->val &&
//               isSymmetric(p->left, q->right) &&
//               isSymmetric(p->right, q->left);
//    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            TreeNode* q = s.top();
            s.pop();

            if (p == NULL && q == NULL)
                continue;
            if (p == NULL || q == NULL)
                return false;
            if (p->val != q->val)
                return false;

            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
    }
};

int main() {}
