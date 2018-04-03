#include<stdio.h>
#include<stack>
using namespace std;
int main() {
    int N;
    while(scanf("%d", &N) == 1 && N) {
        int a[N];
        while(scanf("%d", &a[0]) && a[0]) {
            stack<int> A, C;
            for(int i = 1; i < N; i++)
                scanf("%d", &a[i]);
            for(int i = N; i > 0; i--)
                A.push(i);
            bool can = true;
            for(int i = 0; i < N; i++) {
                if(!C.empty() && C.top() == a[i]){
                    C.pop();
                    continue;
                }
                else {
                    while(!A.empty() && a[i] != A.top()) {
                        C.push(A.top());
                        A.pop();
                    }
                    if(!A.empty() && A.top() == a[i]) {
                        A.pop();
                        continue;
                    } else {
                        can = false;
                        break;
                    }
                }
            }
            printf("%s\n", can ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}
