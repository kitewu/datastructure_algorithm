#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, &depth);
    }

    bool isBalanced(TreeNode* root, int *depth) {
        if(root == NULL) {
            *depth = 0;
            return true;
        }
        int left, right;
        if(isBalanced(root->left, &left) && isBalanced(root->right, &right)) {
            int diff = left - right;
            if(diff <=1 && diff >= -1) {
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }

//    bool isBalanced(TreeNode* root) {
//        if(!root)
//            return true;
//        int left = TreeDeep(root->left);
//        int right = TreeDeep(root->right);
//        int diff = left - right;
//        if(diff < -1 || diff > 1)
//            return false;
//        return isBalanced(root->left) && isBalanced(root->right);
//    }
//
//    int TreeDeep(TreeNode* root){
//        if(!root)
//            return 0;
//        int left = TreeDeep(root->left);
//        int right = TreeDeep(root->right);
//        return 1 + (left > right ? left : right);
//    }
};

int main() {}
