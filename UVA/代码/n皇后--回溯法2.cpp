#include<cstdio>
#include<cstring>
using namespace std;

int C[50], vis[3][50], n, tot = 0, nc = 0;

void search(int cur) {
    int i, j;
    nc++;
    if(cur == n) {
        for(int i = 0; i < n; i++)
            printf("%d ", C[i]);
        printf("\n");
        tot++;
    } else
        for(i = 0; i < n; i++) {
            if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {
                C[cur] = i;
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
                search(cur+1);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
            }
        }
}

int main() {
    while(~scanf("%d", &n)){
        if(n > 18)
            n = 8;
        memset(vis, 0, sizeof(vis));
        search(0);
        printf("%d\n", tot);
        printf("%d\n", nc);
    }
    return 0;
}
