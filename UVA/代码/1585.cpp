#include<stdio.h>
#include<string.h>
#define maxn 100
int main()
{
    int T;
    scanf("%d", &T);
    char s[maxn];
    while(T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int score = 0;
        int cc = 1;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'O')
            {
                score += cc;
                cc++;
            }
            if(s[i] == 'X')
                cc = 1;
        }
        printf("%d\n", score);
    }
}
