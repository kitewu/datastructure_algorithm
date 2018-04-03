#include <cstring>
#include <cstdio>

typedef struct{
    int x;
    int y;
} Point;

bool isRight;
int G[10][10];//棋盘
Point dir[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};//方向数组

//初始化
void Init(Point &current){
    current.x--;
    current.y--;
    memset(G, 0, sizeof(G));
    isRight = false;
}

//操作
bool Operator(Point current, int step, int n){
    G[current.x][current.y] = step;
    if(step == n * n){
        isRight = true;
        return true;
    }
    for(int i = 0; i < 8; i++){
        Point t;
        t.x = current.x + dir[i].x;
        t.y = current.y + dir[i].y;
        if(t.x >= 0 && t.x < n && t.y >= 0 && t.y < n && G[t.x][t.y] == 0){
            if(Operator(t, step + 1, n)){
                return true;
            }
            G[t.x][t.y] = 0;
        }
    }
    return false;
}

//输出
void Show(int n, int xx){
    printf("Case #%d:\n", xx);
    if(isRight){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%3d", G[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("No solution.\n");
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int xx = 1; xx <= N; xx++){
        Point current;
        int n;
        scanf("%d%d%d",&n, &current.x, &current.y);
        Init(current);
        Operator(current, 1, n);
        Show(n, xx);
    }
}
