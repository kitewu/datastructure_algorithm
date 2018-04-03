#include<stdio.h>
#include<string.h>
int main()
{
    int n, k, m;
    while(scanf("%d%d%d", &n, &k, &m) && n && k && m)
    {
        int a[n + 2];
        memset(a, 0, sizeof(a));
        int len = n;
        int pos1 = 1;
        int pos2 = n;
        int j = 0;
        while(len)
        {
            j = 0;
            for(int i = pos1;;i++)
            {
                if(i > n)
                    i = 1;
                if(!a[i])
                    j++;
                if(j == k)
                {
                    pos1 = i;
                    break;
                }
            }
            j = 0;
            for(int i = pos2;;i--)
            {
                if(i <= 0)
                    i = n;
                if(!a[i])
                    j++;
                if(j == m)
                {
                    pos2 = i;
                    break;
                }
            }
            printf("%3d", pos1);
            len--;
            if(pos1 != pos2)
            {
                printf("%3d", pos2);
                len--;
            }
            a[pos1] = a[pos2] = 1;
            if(len)
                printf(",");
            else
                printf("\n");
        }
    }
}
