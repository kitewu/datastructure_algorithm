#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main() {
    char s1[1005];
    char s2[1005];
    gets(s1);
    gets(s2);
    int len = strlen(s1);
    int count = 0;
    int i;
    for(i=0; i<len; i++) {
        if(isdigit(s1[i]) || isalpha(s1[i])){
            if(s2[i] == '1')
                count++;
        }
        else {
            if(s2[i] == '0')
                count++;
        }
    }
    printf("%.02lf", count * 100.0 / len);
}
