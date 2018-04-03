#include<stdio.h>
#define maxn 100010
int a[maxn] = {0};
int main()
{
    for(int i = 1; i <= 100000; i++)
    {
        int temp = i;
        int sum = i;
        while(temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if(a[sum] == 0 || i < a[sum])
            a[sum] = i;
    }
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}
