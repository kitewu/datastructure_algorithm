#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1) >= 0 ? true : false;
    }

    int helper(vector<int>& nums, int start, int end) {
        if(start == end)
            return nums[start];
        else
            return max(nums[start]-helper(nums, start+1,end), nums[end]-helper(nums, start,end-1));
    }
};

int main() {
    Solution s;
    return 0;
}
