#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};
int main() {
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    vector<int> v1 = s.twoSum(v, 9);
    cout << v1[0] << " " << v1[1] << endl;
}
