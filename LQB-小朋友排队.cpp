#include <stdio.h>
#include <string.h>
#define MAX 1000100
typedef long long ll ;
ll t[MAX] , a[100100] , b[100100] ;

ll lowbit(ll x) {
    return x&(-x) ;
}

ll getSum(ll pos) {
    ll sum = 0 ;
    while(pos>0) {
        sum += t[pos] ;
        pos -= lowbit(pos) ;
    }
    return sum ;
}
void update(ll pos) {
    while(pos<MAX) {
        t[pos]++ ;
        pos += lowbit(pos) ;
    }
}
int main() {
    int n;
    scanf("%d",&n) ;
    ll sum = 0 ;
    for(int i = 0 ; i < n ; ++i) {
        scanf("%I64d",&a[i]) ;
        ++a[i];
        b[i] = i-getSum(a[i]) ;
        update(a[i]) ;
    }
    memset(t,0,sizeof(t)) ;
    for(int i = n-1 ; i >= 0 ; --i) {
        b[i] += getSum(a[i]-1) ;
        sum += ((b[i]+1)*b[i])/2;
        update(a[i]) ;
    }
    printf("%I64d\n",sum) ;
    return 0 ;
}
