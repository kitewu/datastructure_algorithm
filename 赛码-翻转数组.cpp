#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int flag[10], len = 0, ni = 1;
    int i=1;
    for(; i<n; i++){
        int t = arr[i]-arr[i-1];
        t = t / (int)abs(t*1.0);
        if(t != ni){
            flag[len++] = i-1;
            ni = (ni == 1 ? -1 : 1);
        }
    }

    if(ni == -1)
        flag[len++] = i-1;

//    for(int j=0; j<len; j++)
//        printf("%d ", flag[j]);
//    printf("\n----%d-----\n", len);

    if(len == 0)
        printf("yes\n");
    else if(len > 2)
        printf("no\n");
    else{
        if(flag[0] == 0 && flag[1] == n-1)
            printf("yes");
        else if(flag[0] == 0)
            arr[flag[1]+1] > arr[flag[0]] ? printf("yes") : printf("no");
        else if(flag[1] == n-1)
            arr[flag[0]-1] < arr[flag[1]] ? printf("yes") : printf("no");
        else
            (arr[flag[1]+1] > arr[flag[0]]) &&
            (arr[flag[0]-1] < arr[flag[1]]) ?
            printf("yes") : printf("no");
    }
}
