#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size <= 0)
            return false;
        //     0 1 2 3 4 len = 5
        //A = [2,3,1,1,4], return true.
        //A = [3,2,1,0,4], return false.
        int maxJump = -1;
        for(int i=0; i<size; i++) {
            if(nums[i] > maxJump)
                maxJump = nums[i];
            if(maxJump >= size-i-1)
                return true;
            if(maxJump == 0)
                return false;
            maxJump--;
        }
        return false;
    }
};

int main() {
}
