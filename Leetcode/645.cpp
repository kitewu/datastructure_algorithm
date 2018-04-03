#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        if(nums.size() == 0)
            return res;
        int arr[nums.size()+1];
        memset(arr, 0, sizeof(int)*(nums.size()+1));
        for(int i=0; i<nums.size(); i++)
            arr[nums[i]]++;
        for(int i=1; i<=nums.size(); i++) {
            if(arr[i] == 0)
                res[1] = i;
            if(arr[i] == 2)
                res[0] = i;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(4);
    vector<int> res = s.findErrorNums(v);
    cout << res[0] << " " << res[1];
    return 0;
}

