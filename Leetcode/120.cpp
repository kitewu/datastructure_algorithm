#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int dp[2][triangle.size()];
        int flag = 0;

        for(int i=0; i<triangle.size(); i++)
            dp[flag][i] = triangle[triangle.size()-1][i];

        for(int i=triangle.size()-2; i>=0; i--) {
            int t = (flag+1)%2;
            for(int j=0; j<=i; j++)
                dp[t][j] = min(dp[flag][j], dp[flag][j+1]) + triangle[i][j];
            flag = t;
        }
        return dp[flag][0];
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }
};

int main() {
    vector<int> v;
    v.push_back(1);

    vector<int> vv;
    vv.push_back(2);
    vv.push_back(3);

    vector<vector<int> > vvv;
    vvv.push_back(v);
    vvv.push_back(vv);
    Solution s;
    s.minimumTotal(vvv);
}
