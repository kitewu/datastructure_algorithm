#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin()+(n-k));
        reverse(nums.begin()+(n-k), nums.begin()+n);
        reverse(nums.begin(), nums.end());
    }

    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (k == 0) return;
        int *temp = new int[n];
        memcpy(temp, nums+(n-k), sizeof(int)*k);
        memcpy(temp+k, nums, sizeof(int)*(n-k));
        memcpy(nums, temp, sizeof(int)*n);
        delete[] temp;
    }
};

int main() {
    Solution s;
    return 0;
}
