#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty())
            return 0;
        int res = 0;
        fun(nums, 0, 0, S, res);
        return res;
    }

    void fun(vector<int>& nums, int cur_sum, int index, int S, int& res) {
        if(index == nums.size()) {
            if(cur_sum == S)
                res++;
            return;
        }
        fun(nums, cur_sum+nums[index], index+1, S, res);
        fun(nums, cur_sum-nums[index], index+1, S, res);
    }
};

int main() {
    Solution s;
    vector<int> v;
    for(int i=0; i<5; i++)
        v.push_back(1);
    cout << s.findTargetSumWays(v, 3) << endl;
    return 0;
}
