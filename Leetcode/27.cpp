#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int begin = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(nums[i] != val)
                nums[begin++] = nums[i];
        return begin;
    }
};

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    Solution s;
    cout << s.removeElement(v, 2);
}
