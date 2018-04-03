#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        int mmin = nums[0], mmax = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > mmax)
                mmax = nums[i];
            if(nums[i] < mmin)
                mmin = nums[i];
        }
        int arr[mmax-mmin+1];
        memset(arr, 0, sizeof(int) * (mmax-mmin+1));
        for(int i=0; i<nums.size(); i++)
            arr[nums[i]-mmin]++;
        for(int i=0; i<mmax-mmin+1; i++)
            if(arr[i] > 1)
                return true;
        return false;
    }
};

int main() {
    return 0;
}

