#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu[2];
        int flag = 0;
        int flag2 = 1;
        int res;
        qu[flag].push(root);
        while(true) {
            res = qu[flag].front()->val;
            while(!qu[flag].empty()) {
                TreeNode* temp = qu[flag].front();
                qu[flag].pop();
                if(temp->left)
                    qu[flag2].push(temp->left);
                if(temp->right)
                    qu[flag2].push(temp->right);
            }
            if(qu[flag2].empty())
                return res;
            flag = flag ^ flag2;
            flag2 = flag ^ flag2;
            flag = flag ^ flag2;
        }
    }
};

int main() {
    return 0;
}
