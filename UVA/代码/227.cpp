#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 5

char maps[maxn][maxn] = {0};
int c_x, c_y;

int move(char c) {
    switch(c) {
    case 'A':
        if(c_y == 0)
            return 0;
        maps[c_y][c_x] = maps[c_y - 1][c_x];
        maps[c_y - 1][c_x] = ' ';
        c_y--;
        break;
    case 'B':
        if(c_y == maxn - 1)
            return 0;
        maps[c_y][c_x] = maps[c_y + 1][c_x];
        maps[c_y + 1][c_x] = ' ';
        c_y++;
        break;
    case 'L':
        if(c_x == 0)
            return 0;
        maps[c_y][c_x] = maps[c_y][c_x - 1];
        maps[c_y][c_x - 1] = ' ';
        c_x--;
        break;
    case 'R':
        if(c_x == maxn - 1)
            return 0;
        maps[c_y][c_x] = maps[c_y][c_x + 1];
        maps[c_y][c_x + 1] = ' ';
        c_x++;
        break;
    default:
        return 0;
    }
    return 1;
}

int main() {

    int N = 1;
    while(gets(maps[0])) {
        int flag = 1;
        if(maps[0][0] == 'Z')  break;
        for(int i = 1; i < maxn; i++)
            gets(maps[i]);
        for(int i = 0 ; i < maxn; i++) {
            for(int j = 0; j < maxn; j++) {
                if(maps[i][j] == ' ') {
                    c_x = j,
                    c_y = i;
                    break;
                }
            }
        }
        char c;
        while(scanf(" %c", &c)) {
            if(c == '0') {
                getchar();
                break;
            }
            if(move(c) == 0)
                flag = 0;
        }
        if(N != 1)
            printf("\n");
        printf("Puzzle #%d:\n", N++);
        if(flag) {
            for(int i = 0; i < maxn; i++) {
                for(int j = 0; j < maxn; j++) {
                    printf("%c", maps[i][j]);
                    if(j != maxn - 1) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        } else
            printf("This puzzle has no final configuration.\n");
        flag = 1;
    }
    return 0;
}
