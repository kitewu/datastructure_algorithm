/**
 *01背包问题
 */
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#define maxInt 0x7FFFFFFF
using namespace std;

///基础方法
int minCoins(vector<int> arr, int aim) {
    if(arr.size() == 0 || aim < 0) return -1;
    int n = arr.size();
    int dp[n][aim+1];
    memset(dp, 0, sizeof(dp));
    for(int j=1; j<=aim; j++)///初始全设为maxInt,因为只有一张钱，只能让对应的目标值设为1
        dp[0][j] = maxInt;
    if(arr[0] <= aim)
        dp[0][arr[0]] = 1;
    int left = 0;
    for(int i=1; i<n; i++) {
        for(int j=1; j<= aim; j++) {
            left = maxInt;
            if(j-arr[i] >= 0 && dp[i-1][j-arr[i]] != maxInt)///用这张钱
                left = dp[i-1][j-arr[i]] + 1;
            dp[i][j] = min(left, dp[i-1][j]);
        }
    }
    return dp[n-1][aim] == maxInt ? -1 : dp[n-1][aim];
}

///优化内存方法
int minCoins1(vector<int> arr, int aim) {
    if(arr.size() == 0 || aim < 0) return -1;
    int n = arr.size();
    int dp[aim+1];
    memset(dp, 0, sizeof(dp));
    for(int j=1; j<=aim; j++)///初始全设为maxInt,因为只有一张钱，只能让对应的目标值设为1
        dp[j] = maxInt;
    if(arr[0] <= aim)
        dp[arr[0]] = 1;
    int left = 0;
    for(int i=1; i<n; i++) {
        for(int j=1; j<= aim; j++) {
            left = maxInt;
            if(j-arr[i] >= 0 && dp[j-arr[i]] != maxInt)
                left = dp[j-arr[i]] + 1;
            dp[j] = min(left, dp[j]);
        }
    }
    return dp[aim] == maxInt ? -1 : dp[aim];
}

int main() {
    int n, aim, t;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        cin >> t;
        arr.push_back(t);
    }
    cin >> aim;
    cout << minCoins(arr, aim);
    return 0;
}

