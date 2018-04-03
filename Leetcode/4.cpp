#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, cur = 0, a = 0, b, mid = (nums1.size() + nums2.size()) / 2;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j])
                a = nums1[i++];
            else
                a = nums2[j++];
            cur++;
            if(cur == mid)
                break;
        }
        if(i == nums1.size()) {
            while(cur ++< mid)
                a = nums2[j++];
            b = nums2[j];
        } else if(j == nums2.size()) {
            while(cur++ < mid)
                a = nums1[i++];
            b = nums1[i];
        } else
            b = nums1[i] <= nums2[j] ? nums1[i] : nums2[j];
        return ((nums1.size() + nums2.size()) % 2 == 0) ? (a + b) / 2.0 : b;
    }
};

int main() {
    Solution s;
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    cout << s.findMedianSortedArrays(v1, v2);
}
