#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:

    vector<vector<int> > res;
    vector<int> path;

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return res;
    }

    void helper(vector<int>& nums, int pos, int target) {
        if(target < 0)
            return;
        if(target == 0) {
            res.push_back(path);
            return;
        }
        for(int i=pos; i<nums.size(); i++) {
            if(i != pos && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            helper(nums, i+1, target-nums[i]);
            path.pop_back();
        }
    }
};

int main() {
}


