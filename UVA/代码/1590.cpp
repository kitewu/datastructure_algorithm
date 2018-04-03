#include<stdio.h>
#include<string.h>
const int maxn = 1005;
int a[maxn][4];
int b[maxn][32];
int re[4];
int N;

void showLine(int* arr) {
    for(int j = 0; j < 32; j++) {
        if(j % 8 == 0 && j)
            printf(".");
        printf("%d ", arr[j]);
    }
    printf("\n");
}

void getBinary(int n) {
    for(int i = 1; i <= 4; i++) {
        int pos = i * 8 - 1;
        int t = a[n][i - 1];
        while(t) {
            b[n][pos--] = t % 2;
            t /= 2;
        }
    }
}

void getDecimal(int* binary) {
    for(int i = 1; i <= 4; i++) {
        int t = i * 8 - 1;
        for(int j = t ; j > t - 8; j--) {
            re[i - 1] = re[i - 1] + binary[j] * (1 << t - j);
        }
    }
}

bool judgeCo(int pos) {
    for(int j = 0; j < N - 1; j++) {
        if(b[j][pos] != b[j + 1][pos]) {
            return false;
        }
    }
    return true;
}

int main() {
    while(~scanf("%d", &N)) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(re, 0, sizeof(re));
        for(int i = 0; i < N; i++) {
            scanf("%d.%d.%d.%d", &a[i][0],&a[i][1],&a[i][2],&a[i][3]);
            getBinary(i);
        }
        int pos;
        int flag = true;
        for(pos = 0; pos < 32; pos++) {
            if(!judgeCo(pos))
                break;
        }
        for(int j = pos; j < 32; j++) b[0][j] = 0;
        getDecimal(b[0]);
        printf("%d.%d.%d.%d\n", re[0],re[1],re[2],re[3]);

        memset(re, 0, sizeof(re));
        for(int j = 0; j < pos; j++) b[0][j] = 1;
        getDecimal(b[0]);
        printf("%d.%d.%d.%d\n", re[0],re[1],re[2],re[3]);
    }
}
/*
3
194.85.160.177
194.85.160.183
194.85.160.178
*/
