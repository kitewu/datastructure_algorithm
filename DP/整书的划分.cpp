#include<cstdio>
#include<cstring>

const int NS=55;

int n,m;
int dp[5][NS][NS];

void init() {
    memset(dp,0,sizeof(dp));
    ///将n划分成最大数不超过k的划分数。
    for (int i=0; i<NS; i++)
        dp[0][0][i]=1;
    for (int i=1; i<NS; i++)
        for (int j=1; j<NS; j++)
            if (i<j)
                dp[0][i][j]=dp[0][i][i];
            else
                dp[0][i][j]=dp[0][i][j-1]+dp[0][i-j][j];

    ///将n划分成k个正整数之和的划分数。
    dp[3][0][0]=1;
    for (int i=1; i<NS; i++)
        for (int j=1; j<=i; j++)
            dp[3][i][j]=dp[3][i-1][j-1]+dp[3][i-j][j];

    ///将n划分成若干奇偶正整数之和的划分数。
    dp[2][0][0]=dp[1][0][0]=1;
    for (int i=1; i<NS; i++)
        for (int j=1; j<=i; j++) {
            dp[2][i][j]=dp[1][i-j][j];
            dp[1][i][j]=dp[1][i-1][j-1]+dp[2][i-j][j];
        }
    for (int i=1; i<NS; i++)
        for (int j=1; j<i; j++) {
            dp[1][i][i]+=dp[1][i][j];
            dp[2][i][i]+=dp[2][i][j];
        }

    ///将n划分成若干不同整数之和的划分数。
    for (int i=0; i<NS; i++)
        dp[4][0][i]=1;
    for (int i=1; i<NS; i++)
        for (int j=1; j<NS; j++)
            if (i<j)
                dp[4][i][j]=dp[4][i][i];
            else
                dp[4][i][j]=dp[4][i][j-1]+dp[4][i-j][j-1];
}

int main() {
    init();
    while (~scanf("%d %d",&n,&m)) {
        printf("%d\n",dp[0][n][n]);
        printf("%d\n",dp[3][n][m]);
        printf("%d\n",dp[0][n][m]);
        printf("%d\n",dp[1][n][n]);
        printf("%d\n\n",dp[4][n][n]);
    }
    return 0;
}
