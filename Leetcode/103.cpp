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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if(!root)
            return res;
        queue<TreeNode*> que[2];
        int flag = 0;
        que[flag].push(root);
        bool zigzag = false;
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
            if(zigzag) {
                for(int i=0, j=cur.size()-1; i<j; i++, j--) {
                    int temp = cur[i];
                    cur[i] = cur[j];
                    cur[j] = temp;
                }
            }
            zigzag = !zigzag;
            res.push_back(cur);
            flag = (flag+1)%2;
        }
        return res;
    }
};

int main() {}

