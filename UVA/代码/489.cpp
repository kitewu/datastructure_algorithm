#include<stdio.h>
#include<string.h>
char s1[1000];
char s2[1000];
int s3[27];
int main()
{
    int N;
    while(scanf("%d%s%s", &N, s1, s2) == 3 && N != -1)
    {
        memset(s3, 0, sizeof(s3));
        int len = strlen(s1);
        for(int i = 0; i < len; i++)
            s3[s1[i] - 'a']++;
        int left = strlen(s1);
        len = strlen(s2);
        int error = 0;
        int failed = 0;
        int win = 0;
        for(int i = 0; i < len; i++)
        {
            if(s3[s2[i] - 'a'] == 0)
                error++;
            else
            {
                left-=s3[s2[i] - 'a'];
                s3[s2[i] - 'a'] = 0;
            }
            if(!left)
            {
                win = 1;
                break;
            }
            if(error == 7)
            {
                failed = 1;
                break;
            }
        }
        printf("Round %d\n", N);
        if(win)
            printf("You win.\n");
        else if(failed)//ÊäÁË
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}
