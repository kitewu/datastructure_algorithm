#include<algorithm>
#include<iostream>
using namespace std;

int dp[5050];

int main() {
    int n, m;
    cin >> n >> m;
    int W[n+1], V[n+1];
    for(int i=1; i<=n; i++)
        cin >> W[i] >> V[i];

    for(int i=1; i<=n; i++) {
        for(int j=m; j>=W[i]; j--) {
            dp[j] = max(dp[j-W[i]] + V[i], dp[j]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
