#include<stdio.h>
#include<ctype.h>
#include<string.h>
char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char r(char ch)
{
    if(isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}
int main()
{
    char s[30];
    while((scanf("%s", s)) == 1)
    {
        int p = 1;
        int m = 1;
        int i = 0;
        int j = strlen(s) - 1;
        for(; i <= j; i++, j--)
        {
            if(s[i] != s[j])
                p = 0;
            if(s[j] != r(s[i]))
                m = 0;
        }
        if(p == 0 && m == 0)
        {
            printf("%s -- is not a palindrome.", s);
        }
        else if(p == 1 && m == 0)
        {
            printf("%s -- is a regular palindrome.", s);
        }
        else if(p == 0 && m == 1)
        {
            printf("%s -- is a mirrored string.", s);
        }
        else if(p == 1 && m == 1)
        {
            printf("%s -- is a mirrored palindrome.",s );
        }
        printf("\n\n");
    }
    return 0;
}
