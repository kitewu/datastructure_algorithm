#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n){
        printf("Discarded cards:");
        queue<int> qu;
        for(int i = 1; i <= n; i++)
            qu.push(i);
        while(qu.size() >= 2){
            printf(" %d", qu.front());
            if(qu.size() != 2)
                printf(",");
            qu.pop();
            qu.push(qu.front());
            qu.pop();
        }
        printf("\nRemaining card: %d\n", qu.front());
    }
    return 0;
}
