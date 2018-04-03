#include <iostream>
#include <stack>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> vals;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {//BFS
            TreeNode* node = nodes.top();
            nodes.pop();
            vals.insert(node->val);
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }
        set<int>::iterator it = vals.begin();
        if (vals.size() > 1)//取第二个元素
            return *(++it);
        else
            return -1;
    }
};

int main() {
    return 0;
}
