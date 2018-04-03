#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    vector<int> ans;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0)
            return res;
        sort(nums.begin(), nums.end());
        dfs(0, ans, nums);
//        for(int i=0; i<res.size(); i++) {
//            for(int j=0; j<res[i].size(); j++)
//                cout << res[i][j] << " ";
//            cout << endl;
//        }
        return res;
    }

    void dfs(int step, vector<int>& ans, vector<int>& nums) {
        res.push_back(ans);
        for(int i=step; i<nums.size(); i++) {
            if(i>step && nums[i] == nums[i-1])
                continue;
            ans.push_back(nums[i]);
            dfs(i+1, ans, nums);
            ans.pop_back();
        }
    }
};

int main() {
    vector<int> vv;
    vv.push_back(1);
    vv.push_back(2);
    vv.push_back(3);
    vv.push_back(4);
    vv.push_back(4);
    Solution s;
    s.subsetsWithDup(vv);
}
