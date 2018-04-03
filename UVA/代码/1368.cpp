#include<stdio.h>
#include<string.h>
#define maxm 55
#define maxn 1010
char s[maxm][maxn] = {0};
int main()
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        int m, n;
        scanf("%d %d",&m, &n);
        int count[n][4];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < m; i++)
        {
            scanf("%s", s[i]);
            for(int j = 0; j < n; j++)
            {
                if(s[i][j] == 'A')
                    count[j][0]++;
                else if(s[i][j] == 'C')
                    count[j][1]++;

                else if(s[i][j] == 'G')
                    count[j][2]++;

                else if(s[i][j] == 'T')
                    count[j][3]++;
            }
        }
        int sum = m * n;
        for(int i = 0; i < n; i++)
        {
            int max = -1;
            int pos = 0;
            for(int j = 0; j < 4; j++)
            {
                if(count[i][j] > max)
                {
                    pos = j;
                    max = count[i][j];
                }
            }
            char c = '0';
            if(pos == 0)
                c = 'A';
            else if(pos == 1)
                c = 'C';
            else if(pos == 2)
                c = 'G';
            else  if(pos == 3)
                c = 'T';
            printf("%c", c);
            sum -= max;
        }
        printf("\n%d\n", sum);
    }
}
