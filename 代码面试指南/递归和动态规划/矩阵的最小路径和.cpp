#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    dp[0][0] = arr[0][0];
    for(int i=1; i<m; i++)
        dp[i][0] = dp[i-1][0]+arr[i][0];
    for(int i=1; i<n; i++)
        dp[0][i] = dp[0][i-1]+arr[0][i];
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
    cout << dp[m-1][n-1] << endl;
}
