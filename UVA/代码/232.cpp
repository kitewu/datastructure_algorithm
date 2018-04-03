#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 15

char s[maxn][maxn];
char across[maxn * maxn][maxn];
char down[maxn * maxn][maxn];
int flag[maxn * maxn];
int R, C;

int isBegin(int r, int c) {
    if(s[r][c] == '*')
        return 0;
    if(r == 0 && c == 0)
        return 1;
    if(isalpha(s[r - 1][c]) && isalpha(s[r][c - 1]))
        return 0;
    return 1;
}

int getAcross(int r, int c) {
    int j = 0;
    int pos = r * C + c;
    int i;
    for(i = c; i < C; i++) {
        if(s[r][i] != '*')
            across[pos][j++] = s[r][i];
        else {
            across[pos][j] = 0;
            break;
        }
    }
    return i;
}

int getDown(int r, int c) {
    int j = 0;
    int pos = r * C + c;
    int i;
    for(i = r; i < R; i++) {
        if(s[i][c] != '*')
            down[pos][j++] = s[i][c];
        else {
            down[pos][j] = 0;
            break;
        }
    }
    return i;
}

int main() {
    int N = 0;
    while(scanf("%d", &R) && R) {
        scanf("%d", &C);
        getchar();
        memset(s, 0, sizeof(s));
        memset(across, 0, sizeof(across));
        memset(down, 0, sizeof(down));
        memset(flag, 0, sizeof(flag));
        for(int i = 0; i < R; i++)
            gets(s[i]);
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(isBegin(i, j))
                    flag[i * C + j] = 1;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C;)
                if(flag[i * C + j] == 1)
                    j = getAcross(i, j);
                else
                    j++;
        for(int i = 0; i < C; i++)
            for(int j = 0; j < R;)
                if(flag[j * C + i] == 1)
                    j = getDown(j, i);
                else
                    j++;
        if(N != 0)
            printf("\n");
        printf("puzzle #%d:\nAcross\n", ++N);
        int count = 0;
        for(int i = 0; i < R * C; i++) {
            count += flag[i];
            if(across[i][0] != 0)
                printf("%3d.%s\n", count, across[i]);
        }
        printf("Down\n");
        count = 0;
        for(int i = 0; i < R * C; i++) {
            count += flag[i];
            if(down[i][0] != 0)
                printf("%3d.%s\n", count, down[i]);
        }
    }
}

