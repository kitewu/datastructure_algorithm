#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char str[30];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(islower(str[i]))
            str[i] = toupper(str[i]);
        else
            str[i] = tolower(str[i]);
    }
    printf("%s", str);
    return 0;
}
