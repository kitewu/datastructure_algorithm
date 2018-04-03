#include<algorithm>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return Helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* Helper(vector<int> &preorder, int begin1, int end1, vector<int> &inorder, int begin2, int end2) {
        if(begin1 > end1 || begin2 > end2)
            return NULL;
        else if(begin1 == end1)
            return new TreeNode(preorder[begin1]);

        TreeNode* root = new TreeNode(preorder[begin1]);
        int i = find(inorder.begin(), inorder.end(), preorder[begin1])-inorder.begin();

        int leftlen = i-begin2;
        root->left = Helper(preorder, begin1+1, begin1+leftlen, inorder, begin2, begin2+leftlen-1);
        root->right = Helper(preorder, begin1+leftlen+1, end1, inorder, begin2+leftlen+1, end2);
        return root;
    }
};

int main() {
    return 0;
}
