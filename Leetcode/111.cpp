#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        return minDepth(root, false);
    }

    int minDepth(TreeNode* root,  bool hasbrother) {
        if(root == NULL)
            return hasbrother ? 0x7FFFFFFF : 0;
        int left = minDepth(root->left, root->right != NULL);
        int right = minDepth(root->right, root->left != NULL);
        return 1 + (left < right ? left : right);
    }
};

int main() {}
