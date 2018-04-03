#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int main(){
    time_t t;
    t = time(0);
    char str[8];
    memset(str, 0, sizeof(str));
    memcpy(str, &t, sizeof(t));
    printf("%ld\n" ,t);
    printf("%s\n" ,str);
    long int a = atoi(str);
    printf("%ld", a);
}
