#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#define maxn 100
int main()
{
    char s[maxn];
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        float sum = 0;
        int len = strlen(s);
        int i = 0;
        for(; i < len;)
        {
            char c = s[i++];
            char sn[10] = {0};
            int snn = 0;
            for(; i<len;)
            {
                if(isdigit(s[i]))
                {
                    sn[snn++] = s[i];
                }
                else
                    break;
                i++;
            }
            int count = atoi(sn);
            if(count == 0)
                count = 1;
            switch(c)
            {
            case 'C':
                sum+=(12.010*count);
                break;
            case 'H':
                sum+=(1.008*count);
                break;
            case 'O':
                sum+=(16.00*count);
                break;
            case 'N':
                sum+=(14.01*count);
                break;
            }
        }
        printf("%.3f\n", sum);
    }
}
