#include<stdio.h>

void m_print(int n, int *A, int cur) {
    if(cur == n) {
        for(int i = 0; i <n ; i++)
            printf("%d ", A[i]);
        printf("\n");
    } else {
        for(int i = 1; i <= n; i++) {
            int ok = 1;
            for(int j = 0; j < cur; j++) {
                if(A[j] == i)
                    ok = 0;
            }
            if(ok) {
                A[cur] = i;
                m_print(n, A, cur + 1);
            }
        }
    }
}

int main() {
    int n;
    while(~scanf("%d", &n)){
        int A[n];
        m_print(n, A, 0);
    }
}
