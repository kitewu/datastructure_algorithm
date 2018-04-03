#include <stdio.h>
#include <string.h>
#define maxn 1000
typedef struct{
    char op[3];//操作指令
    int num[maxn];//操作数
    int length;//操作数的长度
}Moperator;

int oper_num, r, c;
Moperator oper[maxn];

void getOperator(Moperator &oper)
{
    scanf("%s", oper.op);
    if(oper.op[0] != 'E' && oper.op[0] != 'X'){
        scanf("%d", &oper.length);
        for(int i = 0; i < oper.length; i++)
            scanf("%d", &oper.num[i]);
    }else if(oper.op[0] == 'E' && oper.op[1] == 'X'){
        oper.length = 4;
        for(int i = 0; i < 4; i++)
            scanf("%d", &oper.num[i]);
    }
}

bool solve(int &x, int &y)
{
    for(int i = 0; i < oper_num; i++){
        Moperator t = oper[i];
        if(!strcmp(t.op, "DR")){
            int xx = x;
            for(int j = 0; j < t.length; j++)//先删除，再移动
                if(t.num[j] < xx)
                    x--;
                else if(t.num[j] == xx)
                    return false;
        }
        else if(!strcmp(t.op, "DC")){
            int yy = y;
            for(int j = 0; j < t.length; j++)//先删除，再移动
                if(t.num[j] < yy)
                    y--;
                else if(t.num[j] == yy)
                    return false;
        }
        else if(!strcmp(t.op, "IR")){
            int xx = x;
            for(int j = 0; j < t.length; j++)
                if(t.num[j] <= xx)
                    x++;
        }
        else if(!strcmp(t.op, "IC")){
            int yy = y;
            for(int j = 0; j < t.length; j++)
                if(t.num[j] <= yy)
                    y++;
        }
        else if(!strcmp(t.op, "EX")){//交换的点不确定是第一个还是第二个，判断
            if(x == t.num[0] && y == t.num[1]){
                x = t.num[2];
                y = t.num[3];
            }
            else if(x == t.num[2] && y == t.num[3]){
                x = t.num[0];
                y = t.num[1];
            }
        }
    }
    return true;
}

int main()
{
    int N = 0;
    while(scanf("%d%d", &r, &c) &&r && c)
    {
        memset(oper, 0, sizeof(oper));
        scanf("%d", &oper_num);
        if(N > 0)
            printf("\n");
        for(int i = 0; i < oper_num; i++)
            getOperator(oper[i]);
        printf("Spreadsheet #%d\n", ++N);
        int q;
        scanf("%d", &q);
        while(q--){
            int x, xx, y, yy;
            scanf("%d%d", &x, &y);
            xx = x;
            yy = y;
            if(solve(x, y))
                printf("Cell data in (%d,%d) moved to (%d,%d)\n",xx,yy,x,y);
            else printf("Cell data in (%d,%d) GONE\n",xx,yy);
        }
    }
    return 0;
}
