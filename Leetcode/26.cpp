#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        int len = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1])
                nums[len++] = nums[i];
        }

        return len;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(4);
//    nums.push_back(4);
//    nums.push_back(5);
//    nums.push_back(6);
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
}
