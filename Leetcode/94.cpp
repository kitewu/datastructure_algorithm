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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p != 0 || !s.empty()) {
            while(p != 0) {
                s.push(p);
                p = p -> left;
            }
            if(!s.empty()) {
                p = s.top();
                ret.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return ret;
    }
};

int main() {
}
