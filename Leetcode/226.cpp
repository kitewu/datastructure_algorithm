#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* t = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(t);
        return root;
    }

//    TreeNode* invertTree(TreeNode* root) {
//        if(!root)
//            return root;
//        queue<TreeNode*> que;
//        que.push(root);
//        while(!que.empty()) {
//            TreeNode* top = que.front();
//            que.pop();
//            TreeNode* t = top->left;
//            top->left = top->right;
//            top->right = t;
//            if(top->left)
//                que.push(top->left);
//            if(top->right)
//                que.push(top->right);
//        }
//        return root;
//    }
};

int main() {}

