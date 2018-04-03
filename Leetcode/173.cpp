#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root) {
            ss.push(root);
            root = root->left;
        }
    }

    bool hasNext() {
        return !ss.empty();
    }

    int next() {
        TreeNode *t = ss.top();
        ss.pop();
        if(t->right) {
            TreeNode *p = t->right;
            while(p) {
                ss.push(p);
                p = p->left;
            }
        }
        return t->val;
    }
private:
    stack<TreeNode*> ss;
};

int main() {}
