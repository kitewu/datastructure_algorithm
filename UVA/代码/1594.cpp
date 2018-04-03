#include<stdio.h>
#include<string.h>
#include<math.h>
int m;

bool allZero(int* a)
{
    for(int i = 0; i < m; i++)
        if(a[i] != 0)
            return false;
    return true;
}

int main()
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &m);
        int a[m + 1];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        int count = 0;
        bool r = true;
        while(true)
        {
            a[m] = a[0];
            if(allZero(a)){
                r = false;
                break;
            }
            if(count == 1001)
                break;
            for(int i = 0; i < m; i++)
                a[i] = (int)fabs(a[i] - a[i + 1]);
            count++;
        }
        if(r)
            printf("LOOP\n");
        else
            printf("ZERO\n");
    }
}
