#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <queue>
using namespace std;

const int maxt = 1010;

int main()
{
    int t;
    int kase = 0;
    while(scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++kase);
        map<int, int> maps;
        queue<int> que[maxt];
        queue<int> q;
        for(int i = 0 ; i < t; i++)
        {
            int m;
            scanf("%d", &m);
            while(m--)
            {
                int temp;
                scanf("%d", &temp);
                maps[temp] = i;
            }
        }
        char s[10];
        while(scanf("%s", s))
        {
            if(s[0] == 'S')
                break;
            else if(s[0] == 'D') //出队
            {
                int t = q.front();
                if(!que[t].empty())
                {
                    printf("%d\n", que[t].front());
                    que[t].pop();
                    if(que[t].empty())
                        q.pop();
                }
            }
            else if(s[0] == 'E') //入队
            {
                int num;
                scanf("%d", &num);
                int que_num = maps[num];
                if(que[que_num].empty())
                    q.push(que_num);
                que[que_num].push(num);
            }
        }
        printf("\n");
    }
    return 0;
}
