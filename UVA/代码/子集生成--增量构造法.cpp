#include<stdio.h>

void print_subset(int n, int *A, int cur) {
    for(int i = 0; i < cur; i++)
        printf("%d", A[i]);
    printf("\n");
    int s = cur ? A[cur - 1] + 1 : 0;
    for(int i = s; i < n; i++) {
        A[cur] = i;
        print_subset(n, A, cur + 1);
    }
}

int main() {
    int n;
    while(scanf("%d", &n)) {
        int A[n];
        print_subset(n, A, 0);
    }
    return 0;
}
