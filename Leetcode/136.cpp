#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0; i<nums.size(); i++)
            x ^= nums[i];
        return x;
    }
};

int main() {
    return 0;
}


