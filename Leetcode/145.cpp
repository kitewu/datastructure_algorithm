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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> path;
        if(root==NULL)return path;

        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* cur = NULL;
        while(!stk.empty()) {
            cur = stk.top();
            if(cur->left ==NULL && cur->right ==NULL) {
                path.push_back(cur->val);
                stk.pop();
            } else {
                if(cur->right) {
                    stk.push(cur->right);
                    cur->right = NULL;
                }
                if(cur->left) {
                    stk.push(cur->left);
                    cur->left = NULL;
                }
            }
        }
        return path;
    }
};

int main() {
}

