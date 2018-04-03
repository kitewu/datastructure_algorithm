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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> ss;
        ss.push(root);
        while(!ss.empty()) {
            TreeNode *t = ss.top();
            ss.pop();
            res.push_back(t->val);
            if(t->right)
                ss.push(t->right);
            if(t->left)
                ss.push(t->left);
        }
        return res;
    }
};

int main() {
    return 0;
}
