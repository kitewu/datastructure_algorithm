#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<string> > printTree(TreeNode* root) {
        vector<vector<string> > ret;
        if(!root)
            return ret;
        int depth = getDepth(root)-1;
        int width = (2<<depth)-1;
        vector<vector<string> > res(depth+1, vector<string>(width, ""));
        getRes(root, res, 0, depth, 0, width);
        return res;
    }

    void getRes(TreeNode* root, vector<vector<string> > &res, int curDepth, int depth, int left, int right) {
        if(curDepth > depth || !root || left > right)
            return;
        int mid = left+(right-left)/2;
        char c[8];
        string val = itoa(root->val, c, 10);
        res[curDepth][mid] = val;
        if(root->left)
            getRes(root->left, res, curDepth+1, depth, left, mid-1);
        if(root->right)
            getRes(root->right, res, curDepth+1, depth, mid+1, right);
    }

    int getDepth(TreeNode* root) {
        if(!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    Solution s;
    s.printTree(root);
    return 0;
}
