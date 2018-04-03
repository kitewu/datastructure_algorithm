#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//非递归方式
void preOrderRecur(TreeNode* tree) {
    if(NULL == tree)
        return;
    stack<TreeNode*> ss;
    ss.push(tree);
    while(!ss.empty()) {
        TreeNode *t = ss.top();
        ss.pop();
        cout << t->val << " ";
        if(t->left)
            ss.push(t->right);
        if(t->right)
            ss.push(t->left);
    }
}

//递归方式
void preOrderRecur1(TreeNode* tree) {
    if(NULL == tree)
        return;
    cout << tree->val << " ";
    preOrderRecur1(tree->left);
    preOrderRecur1(tree->right);
}

int main() {
    return 0;
}
