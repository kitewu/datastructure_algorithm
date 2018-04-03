#include<stdio.h>
int main() {
    long long n;
    scanf("%I64d", &n);
    if(n % 2 == 0)
        printf("%lld", (1 + n) * (n / 2));
    else
        printf("%lld", (1 + n) / 2 * n);
    return 0;
}
