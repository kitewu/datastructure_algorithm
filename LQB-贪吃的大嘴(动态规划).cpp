#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 20000+7;
const int INF = 0x3f3f3f3f;

int d[maxn];

struct Node {
    int del,num;
} a[maxn];

int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&a[i].del,&a[i].num);
    for(int i=0; i<maxn; i++) d[i] = INF;

    d[0] = 0;
    for(int i=0; i<n; i++) { ///i种小蛋糕
        for(int j=0; j<a[i].num; j++) {///j 小蛋糕个数
            for(int k=m; k>=a[i].del; k--) {///k 美味度 m目标值
                d[k] = min(d[k],d[k-a[i].del]+1);
            }
        }
    }
    if(d[m] == INF) printf("><\n");
    else printf("%d\n",d[m]);
    return 0;
}


