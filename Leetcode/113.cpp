#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > ret;
    void help(TreeNode *root, vector<int> cur, int target) {
        cur.push_back(root->val);
        if(!root->left && !root->right) {
            if(root->val == target)
                ret.push_back(cur);
            return;
        }
        if(root->left)
            help(root->left, cur, target-root->val);
        if(root->right)
            help(root->right, cur, target-root->val);
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if(!root)
            return ret;
        vector<int> temp;
        help(root, temp, sum);
        return ret;
    }
};

int main() {}
