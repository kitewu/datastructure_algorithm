#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1, j = m - 1, k = n - 1;
        while(j >= 0 && k >= 0)
            if(nums1[j] < nums2[k])
                nums1[i--] = nums2[k--];
            else
                nums1[i--] = nums1[j--];
        while(k >= 0)
            nums1[i--] = nums2[k--];
    }
};

int main() {
    Solution s;
    vector<int> nums1(1);
    nums1.push_back(1);
    vector<int> nums2;
    s.merge(nums1, 1, nums2, 0);
    return 0;
}
