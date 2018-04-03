#include<string.h>
#include<stdio.h>
#define maxn 100010

char s[maxn], t[maxn];

int main()
{
    while(scanf("%s%s", s, t) == 2)
    {
        int lens = strlen(s);
        int lent = strlen(t);
        int flag = 0;
        for(int i = 0; i <= lent - lens; i++)
        {
            if(t[i] == s[0])
            {
                int j = i;
                int k = 0;
                for(; j < lent && k < lens;)
                {
                    if(t[j] == s[k])
                    {
                        k++;
                    }
                    j++;
                }
                if(k == lens)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
