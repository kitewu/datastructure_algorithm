#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates, 0, 0, target, path, res);
        return res;
    }

    void helper(vector<int>& nums,
                int pos,
                int base,
                int target,
                vector<int> &path,
                vector<vector<int> > &res) {
        if(base == target){
            res.push_back(path);
            return;
        }
        if(base > target)
            return;
        for(int i=pos; i<nums.size(); i++){
            path.push_back(nums[i]);
            helper(nums, i, base+nums[i], target, path, res);
            path.pop_back();
        }
    }
};

int main() {
}
