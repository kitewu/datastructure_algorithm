#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return reBuiled(nums, 0, nums.size());
    }

    TreeNode* reBuiled(vector<int>& nums, int begin, int end) {
        if(begin >= end) return NULL;
        int mid = (begin + end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = reBuiled(nums, begin, mid);
        root->right = reBuiled(nums, mid+1, end);
        return root;
    }
};

int main() {
    return 0;
}
