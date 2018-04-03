#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char a[105], b[105];
    int i, j;
    while(1) {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        gets(a);
        i = 0;
        j = strlen(a)-1;
        while(isspace(a[i])) i++;
        while(isspace(a[j])) j--;
        if(i <= j){
            memcpy(b, a+i, j-i+1);
            puts(b);
            if(!strcmp(b, "END"))
                break;
        }
    }
    return 0;
}
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//int main() {
//    char x[101],y[101],z[101];
//    int n,m,i,flag=0,j=0,k=0;
//    while(1) {
//        memset(x,0,sizeof(x));
//        memset(y,0,sizeof(y));
//        memset(z,0,sizeof(z));
//        gets(x);
//        n = strlen(x);
//        for(i=0; i<n; i++) {
//            if(isspace(x[i])) {
//                if(flag==0) {
//                    continue;
//                } else {
//                    y[j]=x[i];
//                    j++;
//                }
//            } else {
//                flag++;
//                y[j]=x[i];
//                j++;
//            }
//        }
//        m = strlen(y);
//        flag=0;
//        for(j=m-1; j>=0; j--) {
//            if(isspace(y[j])) {
//                if(flag==0) {
//                    continue;
//                } else {
//                    z[k]=y[j];
//                    k++;
//                }
//            } else {
//                flag++;
//                z[k]=y[j];
//                k++;
//            }
//        }
//        m = strlen(z);
//        for(k=m-1; k>=0; k--)
//            printf("%c",z[k]);
//        printf("\n");
//        if(!strcmp(z, "DNE")) {
//            break;
//        }
//
//        flag=0;
//        j=0;
//        k=0;
//    }
//    return 0;
//}
