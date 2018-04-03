#include<stdio.h>
#include<string.h>
#define maxn 11000
int main()
{
    char s1[maxn] = {0};
    char s2[maxn] = {0};
    while(scanf("%s%s", s1, s2) == 2)
    {
        int len = 0;
        int flag = 1;
        int d1[maxn] = {0};
        int d2[maxn] = {0};
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        for(int i = 0; i < len1; i++)
            d1[i] = s1[i] - '0';
        for(int i = 0; i < len2; i++)
            d2[i] = s2[i] - '0';
        int i;
        for(i = 0; i < len1; i++)
        {
            flag = 1;
            int j = 0;
            int k = i;
            for(; j < len2 && k < len1; j++, k++)
            {
                if(d1[k] + d2[j] > 3)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            len = i + ((len1 - i) > len2 ? (len1 - i) : len2);
        //    printf("%d\n", );
        else
            len = len1 + len2;
        for(i = 0; i < len2; i++)
        {
            flag = 1;
            int j = 0;
            int k = i;
            for(; j < len1 && k < len2; j++, k++)
            {
                if(d1[j] + d2[k] > 3)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
        {
            if((i + ((len2 - i) > len1 ? (len2 - i) : len1)) < len)
                len = i + ((len2 - i) > len1 ? (len2 - i) : len1);
        }
        else
            len = len1 + len2;
        printf("%d\n", len);
    }
}
