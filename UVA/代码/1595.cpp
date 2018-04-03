#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

const int maxn = 20010;
set<int> s[maxn];
int a[maxn];
double sy = 0;
bool flag = true;

bool judge(const set<int> &se)
{
    if(se.size() > 0)
    {
        int n = 0;
        for(set<int>::iterator it = se.begin(); it != se.end(); it++)
            a[n++] = *it;
        int i = 0;
        int j = se.size() - 1;
        if(flag)
        {
            sy = (a[i] + a[j]) * 1.0 / 2;
            flag = false;
        }
        for(; i <= j; i++, j--)
        {
            if((a[i] + a[j]) * 1.0 / 2 != sy)
                return false;
        }
    }
    return true;
}

int main()
{
    int T;
    int N;
    int x, y;
    scanf("%d", &T);
    while(T--)
    {
        for(int i = 0; i < maxn; i++) s[i].clear();
        flag = true;
        scanf("%d", &N);
        while(N--)
        {
            scanf("%d%d", &x, &y);
            if(y < 0)
                s[-y + 10005].insert(x);
            else
                s[y].insert(x);
        }
        bool issy = true;
        for(int i = 0; i < maxn; i++)
        {
            if(!judge(s[i]))
            {
                issy = false;
                break;
            }
        }
        printf("%s\n", issy ? "YES" : "NO");
    }
}
/*
3
5
-2 5
0 0
6 5
4 0
2 3
4
2 3
0 4
4 0
0 0
4
5 14
6 10
5 10
6 14
*/
