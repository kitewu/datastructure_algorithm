#include<math.h>
#include<stdio.h>
#include<string.h>

const int maxn = 50;
bool isp[maxn];
int vis[maxn];
int A[maxn];
int n;

bool is_prime(int n) {
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

void init() {
    memset(isp, 0, sizeof(isp));
    for(int i = 2; i <= maxn; i++)
        isp[i] = is_prime(i);
}

void dfs(int cur) {
    if(cur == n && isp[A[0] + A[n - 1]]) {
        for(int i = 0; i < n; i++) {
            if(i)
                printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    } else {
        for(int i = 2; i <= n; i++) {
            if(!vis[i] && isp[i + A[cur - 1]]) {
                A[cur] = i;
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    init();
    int kase = 0;
    while(scanf("%d", &n) == 1 && n > 0) {
        if(kase > 0)
            printf("\n");
        printf("Case %d:\n", ++kase);
        memset(vis, 0, sizeof(vis));
        A[0] = 1;
        dfs(1);
    }
}
