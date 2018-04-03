#include<stdio.h>
#include<string.h>

const int maxn = 1010;
int a[maxn][maxn];

bool judge() {
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++) {
            if(a[i][j] != 0 || a[j][i] != 0)
                return false;
        }
    return true;
}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        memset(a, 0, sizeof(a));
        int x, y;
        while(n--) {
            scanf("%d%d", &x, &y);
            a[x][y]++;
            a[y][x]--;
        }
        if(n % 2 == 1) {
            printf("NO\n");
            continue;
        }
        if(judge())
            printf("YES\n");
        else
            printf("NO\n");
    }
}
