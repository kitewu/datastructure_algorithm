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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> que[2];
        int flag = 0;
        que[flag].push(root);
        while(!que[flag].empty()) {
            vector<int> cur;
            while(!que[flag].empty()) {
                TreeNode* t = que[flag].front();
                que[flag].pop();
                cur.push_back(t->val);
                if(t->left)
                    que[(flag+1)%2].push(t->left);
                if(t->right)
                    que[(flag+1)%2].push(t->right);
            }
            res.push_back(cur[cur.size()-1]);
            flag = (flag+1)%2;
        }
        return res;
    }
};

int main() {}

