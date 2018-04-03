#include<stdio.h>
#include<string.h>
#define maxn 10010
int a[10010][10];
int main()
{
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= 10000; i++)
    {
        int t = i;
        while(t)
        {
            a[i][t % 10]++;
            t /= 10;
        }
        for(int j = 0; j < 10; j++)
        {
            a[i][j] += a[i - 1][j];
        }
    }
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        printf("%d", a[n][0]);
        for(int i = 1; i < 10; i++)
        {
            printf(" %d", a[n][i]);
        }
        printf("\n");
    }
}
