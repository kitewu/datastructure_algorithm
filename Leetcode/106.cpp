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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return reBuild(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* reBuild(vector<int>& inorder, int inBegin, int inEnd, vector<int>& postorder, int poBegin, int poEnd) {
        if(inBegin > inEnd || poBegin > poEnd)
            return NULL;
        else if(poBegin == poEnd)
            return new TreeNode(postorder[poEnd]);

        TreeNode *root = new TreeNode(postorder[poEnd]);

        int leftLen = find(inorder.begin(), inorder.end(), postorder[poEnd])-inorder.begin() - inBegin;

        root->left = reBuild(inorder, inBegin, inBegin+leftLen-1, postorder, poBegin, poBegin+leftLen-1);
        root->right = reBuild(inorder, inBegin+leftLen+1, inEnd, postorder, poBegin+leftLen, poEnd-1);
        return root;
    }
};

int main() {
    return 0;
}
