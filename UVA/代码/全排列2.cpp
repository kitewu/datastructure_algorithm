#include<stdio.h>
#include<algorithm>
using namespace std;

void m_print(int n, int *P, int *A, int cur) {
    if(cur == n) {
        for(int i = 0; i <n ; i++)
            printf("%d ", A[i]);
        printf("\n");
    } else {
        for(int i = 0; i < n; i++) {
            if(!i || P[i] != P[i - 1]) {
                int c1 = 0, c2 = 0;
                for(int j = 0; j < cur; j++)
                    if(A[j] == P[i])
                        c1++;
                for(int j = 0; j < n; j++)
                    if(P[j] == P[i])
                        c2++;
                if(c1 < c2) {
                    A[cur] = P[i];
                    m_print(n, P, A, cur + 1);
                }
            }
        }
    }
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int A[n];
        int P[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &P[i]);
        sort(P, P + n);
        m_print(n, P, A, 0);
    }
}

