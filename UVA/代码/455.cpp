#include<stdio.h>
#include<string.h>
#define maxn 100
int main()
{
    int T;
    char s[maxn];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int r = 0;
        for(int i = 1; i <= len / 2; i++)
        {
            if(len % i == 0)
            {
                r = i;
                char temp0[i+1];
                memcpy(temp0, s, i);
                temp0[i] = 0;
                for(int j = 0; j < len; j += i)
                {
                    char temp[i+1];
                    memcpy(temp, s + j, i);
                    temp[i] = 0;
                    if(strcmp(temp, temp0) != 0)
                    {
                        r = 0;
                        break;
                    }
                }
                if(r != 0)
                {
                    printf("%d\n", r);
                    if(T != 0)
                        printf("\n");
                    break;
                }
            }
        }
        if(r == 0)
        {
            printf("%d\n", len);
            if(T != 0)
                printf("\n");
        }
    }
}
