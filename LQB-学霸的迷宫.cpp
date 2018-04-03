#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define NUM 505

struct Node {
    int x;
    int y;
    int num_step;
    string step;
    Node(int i,int j) {
        x = i;
        y = j;
        num_step = 0;
        step = "";
    }
};

int arr[NUM][NUM];
int m,n;
char dir_c[5] = {'U','D','L','R'};
int dir[5][2] = {
    {-1,0},  ///UP
    {1,0}, ///DOWM
    {0,-1}, ///LEFT
    {0,1}   ///RIGHT
};
///最优解步骤
string ans;
///最优解步数
int num_ans;
///最优解标记变量
int is_finish = 0;

///检查当前节点是否合法
int check(Node tmp) {
    int i = tmp.x, j = tmp.y;
    if(i < 1 || j < 1 || i > m || j > n || 1 == arr[i][j])
        return 0;
    return 1;
}

int bfs() {
    queue<Node> Q_node;
    Node start(1,1);
    Node tmp(0,0);

    Q_node.push(start);

    while(false == Q_node.empty()) {
        Node now = Q_node.front();
        Q_node.pop();

        if(now.x == m && now.y == n) {
            is_finish = 1;
            num_ans = now.num_step;
            if("" == ans)
                ans = now.step;
            else if(ans > now.step)
                ans = now.step;
            continue;
        }

        if(is_finish)
            if(now.num_step > num_ans)
                continue;

        for(int i = 0; i < 4; i++) {
            tmp.x = now.x+dir[i][0];
            tmp.y = now.y+dir[i][1];
            ///记录下一步方向
            tmp.step = now.step + dir_c[i];
            tmp.num_step = now.num_step + 1;

            if(check(tmp)) {
                Q_node.push(tmp);
                ///标记来时路线，不再进行判断
                arr[tmp.x][tmp.y] = 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d%d",&m,&n);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%1d",&arr[i][j]);
        }
    }

    bfs();

    printf("%d\n%s\n",num_ans,ans.c_str());
    return 0;
}
