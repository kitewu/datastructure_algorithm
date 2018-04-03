#include<iostream>
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
            ans.push_back(nums[i]);
            dfs(i+1, ans, nums);
            ans.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    s.subsets(v);
}
