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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> arr[2];
        int a = 0;
        arr[a].push(root);
        while(!arr[a].empty()) {
            int max = arr[a].front()->val;
            b = (a+1) % 2;
            while(!arr[a].empty()) {
                TreeNode* t = arr[a].front();
                if(t->val > max)
                    max = t->val;
                arr[a].pop();
                if(t->left)
                    arr[b].push(t->left);
                if(t->right)
                    arr[b].push(t->right);
            }
            res.push_back(max);
            a = a^b;
            b = a^b;
            a = a^b;
        }
        return res;
    }
};

int main() {
    return 0;
}
