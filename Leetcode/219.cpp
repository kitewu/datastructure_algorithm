#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty())
            return false;
        map<int, int> mmap;
        for(int i=0; i<nums.size(); i++){
            if(mmap.find(nums[i]) != mmap.end() && i-mmap[nums[i]] <= k)
                return true;
            mmap[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    return true;
}
