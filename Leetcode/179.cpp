#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    static bool compare(int a, int b) {
        char c[20];
        return string(itoa(a, c, 10)) + string(itoa(b, c, 10)) >
        string(itoa(b, c, 10)) + string(itoa(a, c, 10));
    }

    string largestNumber(vector<int>& nums) {
        string result;
        if(nums.empty())
            return result;
        sort(nums.begin(), nums.end(), compare);
        char c[20];
        for(int i=0; i<nums.size(); i++)
            result += string(itoa(nums[i], c, 10));
        return result[0] == '0' ? "0" : result;  //[0,0]应返回“0”而不是“00”
    }
};

int main() {
    Solution s;
    vector<int> vv;
    for(int i=35; i>=0; i--) {
        vv.push_back(i+1);
    }
    vv.push_back(100);
    cout << s.largestNumber(vv);
    return 0;
}
