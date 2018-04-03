#include <stdio.h>
int main() {
    int a,b,c,p,q;
    while(~scanf("%d%d",&a,&b)) {
        p = a;
        q = b;
        a < b ? (a ^= b ^= a ^= b) : 1;
        while(c = a % b) {
            a = b;
            b = c;
        }
        printf("%d %d\n", b, p*q/b);
    }
    return 0;
}
