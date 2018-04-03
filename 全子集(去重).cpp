#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > res;
vector<int> ans;

void show() {
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

void dfs(int step, vector<int> &nums) {
    res.push_back(ans);
    for(int i = step; i < nums.size(); i++) {
        if(i > step && nums[i] == nums[i - 1])
            continue;
        ans.push_back(nums[i]);
        dfs(i + 1, nums);
        ans.pop_back();
    }
}

int main() {
    vector<int> vv;
    int i;
    for(i=1; i<=4; i++)
        vv.push_back(i);
    vv.push_back(i-1);
    sort(vv.begin(), vv.end());
    dfs(0, vv);
    show();
    return 0;
}

