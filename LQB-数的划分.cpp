#include<cstdio>
#include<cstring>
using namespace std;

unsigned long long d[100+7];

int main() {
    int n;
    scanf("%d",&n);
    memset(d,0,sizeof(d));
    d[0] = 1;
    for(int i=1; i<=n; i++) ///i枚举每一种种类
        for(int j=0; j<=n; j++) /// 枚举每一种目标结果，n为最终结果
            if(j - i >= 0)
                d[j] = d[j] + d[j-i];
    printf("%llu\n",d[n]);
    return 0;
}
