#include<string.h>
#include<stdio.h>
#define maxn 105
int less(char* s, int p, int q, int n){
    for(int i = 0; i < n; i++)
        if(s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i) % n];
    return 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        char s[maxn];
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(less(s, i, ans, n))
                ans = i;
        }
        for(int i = 0; i < n; i++){
            putchar(s[(i + ans) % n]);
        }
        printf("\n");
    }
    return 0;
}
