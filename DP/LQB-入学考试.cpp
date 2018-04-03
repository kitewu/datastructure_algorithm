#include<iostream>
using namespace std;

int dp[1010];

int main() {
    int T, M;
    cin >> T >> M;
    int v[M+1], w[M+1];
    for(int i=1; i<=M; i++)
        cin >> w[i] >> v[i];

    for(int i=1; i<=M; i++) {///种类
        for(int j=T; j>=w[i]; j--) {///重量
            dp[j] = max(dp[j-w[i]] + v[i], dp[j]);
        }
    }
    cout << dp[T] << endl;
}
