#include<stdio.h>
int main() {
    int cock,hens,chick,m,n,a,b,c,d,k;
    scanf("COCK,HEN,CHICK,MONEY,CHICKS");
    while(scanf("%d,%d,%d/%d,%d,%d",&a,&b,&c,&d,&m,&n)!=EOF) {
        for(cock=0; cock<=n; cock++) { //输出表头或cannot buy
            hens=(m*d-c*n-cock*(a*d-c))/(b*d-c);
            chick=m-cock-hens;
            if(cock*a*d+hens*b*d+chick*c==m*d&&hens>=0&&chick>=0) {
                k=1;
                break;
            } else
                k=0;
        }



        if(k==1)
            printf("COCKS,HENS,CHICKS\n");
        else if(k==0||m==0||n==0)
            printf("Cannot buy!\n");




        for(cock=0; cock<=n; cock++) { //输出可能的答案
            hens=(m*d-c*n-cock*(a*d-c))/(b*d-c);
            chick=m-cock-hens;
            if(cock*a*d+hens*b*d+chick*c==m*d&&hens>=0&&chick>=0) {
                printf("%d,%d,%d\n",cock,hens,chick);
            }

        }




        printf("\n");
    }
    return 0;
}

