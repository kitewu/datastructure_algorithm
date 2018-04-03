#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        queue<TreeLinkNode*> que[2];
        int flag = 0;
        que[flag].push(root);
        while(!que[flag].empty()) {
            while(!que[flag].empty()) {
                TreeLinkNode* t = que[flag].front();
                que[flag].pop();
                if(que[flag].empty())
                    t->next = NULL;
                else
                    t->next = que[flag].front();
                if(t->left)
                    que[(flag+1)%2].push(t->left);
                if(t->right)
                    que[(flag+1)%2].push(t->right);
            }
            flag = (flag+1)%2;
        }
    }
};

int main() {
}
