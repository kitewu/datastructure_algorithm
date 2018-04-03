#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j <= i; j++)
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end()) {
                    dp[i + 1] = true;
                    break;
                }
        return dp[s.size()];
    }

    bool wordBreak1(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (dp[i]) {
                for (int j = 1; i + j - 1 < n; j++)
                    if (find(wordDict.begin(), wordDict.end(), s.substr(i, j)) != wordDict.end())
                        dp[i + j] = true;
            }
        }
        return dp[n];
    }
};

int main() {
}
