#include<cstdio>
#include<cstring>

const int NS=101;

int n,m;
int dp[NS][NS];

void init() {
    memset(dp,0,sizeof(dp));
    for (int i=0; i<NS; i++)
        dp[0][i]=1;
    for (int i=1; i<NS; i++)
        for (int j=1; j<NS; j++)
            if (i<j)
                dp[i][j]=dp[i][i];
            else
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
}

int main() {
    init();
    scanf("%d",&n);
    printf("%d\n",dp[n][n]);
    return 0;
}
