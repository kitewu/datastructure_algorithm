#include<stdio.h>
int main()
{
    int i = 3;
    int *p = &i;
    printf("%d", sizeof(p));
}
