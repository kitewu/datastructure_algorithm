#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
char cc[10];
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        string cur;
        path(res, root, cur);
        return res;
    }

    void path(vector<string> &res, TreeNode* root, string cur) {
        if(NULL == root)
            return;
        if(root->left == NULL && root->right == NULL) {
            cur += string(itoa(root->val, cc, 10));
            res.push_back(cur);
            return;
        }
        string right = cur;
        if(root->left != NULL) {
            cur += string(itoa(root->val, cc, 10)) + "->";
            path(res, root->left, cur);
        }
        if(root->right != NULL) {
            right += string(itoa(root->val, cc, 10)) + "->";
            path(res, root->right, right);
        }
    }
};

int main() {
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    Solution s;
    s.binaryTreePaths(t);
}
