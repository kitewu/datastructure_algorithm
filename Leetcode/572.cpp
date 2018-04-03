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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)
            return false;
        if(s->val == t->val && isTheSame(s, t))
            return true;
        else
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        return false;
    }

    bool isTheSame(TreeNode* s, TreeNode* t) {
        ///两个数同时到达底端，说明完全相等
        if(s == NULL && t == NULL)
            return true;
        ///当其中有个已到达底端但另一个还没有，返回false
        if((s != NULL && t == NULL) || (s == NULL && t != NULL))
            return false;
        ///当前val相等，继续对左子树右子树做同样的事，如果都true，则返回true
        if(s->val == t->val && isTheSame(s->left , t->left) && isTheSame(s->right , t->right))
            return true;
        return false;
    }
};

int main() {
    return 0;
}
