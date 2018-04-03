#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int max = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > max)
                max = nums[i];
        if(max == 0)
            return 1;
        int arr[max + 2];
        memset(arr, 0, (max + 2) * sizeof(int));
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                arr[nums[i]] = 1;
        }
        for(int i = 1; i <= max + 1; i++){
            if(arr[i] == 0)
                return i;
        }
    }
};

int main(){
}
