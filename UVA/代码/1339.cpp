#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 110;
char s1[maxn];
char s2[maxn];
int a1[26];
int a2[26];
int main()
{
    while(scanf("%s%s", s1, s2) != EOF){
        memset(a1, 0, sizeof(a1));
        memset(a2, 0, sizeof(a2));
        int len = strlen(s1);
        for(int i = 0; i < len; i++)
            a1[s1[i] - 'A']++;
        len = strlen(s2);
        for(int i = 0; i < len; i++)
            a2[s2[i] - 'A']++;
        sort(a1, a1 + 26);
        sort(a2, a2 + 26);
        int flag = 1;
        for(int i = 0; i < 26; i++){
            if(a1[i] != a2[i]){
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("%s\n", "YES");
        else
            printf("%s\n", "NO");
    }
}
