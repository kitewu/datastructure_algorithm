#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 10010;
int a[maxn];

int main()
{
    int N = 0;
    int m, n;
    while(scanf("%d%d", &m, &n) == 2 && m)
    {
        for(int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        sort(a, a + m);
        printf("CASE# %d:\n", ++N);
        while(n--)
        {
            int x;
            scanf("%d", &x);
            int p = lower_bound(a, a + m, x) - a;
            if(a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}
