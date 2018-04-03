#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> mid;
        inorder(root, mid);
        int i=0, j=mid.size()-1;
        while(i < j) {
            if(mid[i] + mid[j] == k)
                return true;
            else if(mid[i] + mid[j] > k)
                j--;
            else if(mid[i] + mid[j] < k)
                i++;
        }
        return false;
    }

    void inorder(TreeNode* node, vector<int> &mid) {
        if(!node)
            return;
        inorder(node->left, mid);
        mid.push_back(node->val);
        inorder(node->right, mid);
    }
};

int main() {
    return 0;
}
