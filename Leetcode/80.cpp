#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        int pre = 1;
        int cur = 2;
        while(cur < nums.size()){
            if(nums[cur] == nums[pre] && nums[cur] == nums[pre-1])
                cur++;
            else
                nums[++pre] = nums[cur++];
        }
        return pre+1;
    }

    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            nums.size();
        int index = 0;
        int count = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[index]) {
                nums[++index] = nums[i];
                count = 1;
            } else {
                if(++count < 3)
                    nums[++index] = nums[i];
            }
        }
        return ++index;
    }
};

int main() {
    Solution s;
    vector<int> v;
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(3);
//    v.push_back(3);
    cout << s.removeDuplicates(v);
}
