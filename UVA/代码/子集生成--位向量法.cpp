#include<iostream>
using namespace std;

void print_subset(int n, int *A, int cur) {
    if(cur == n) {
        for(int i = 0; i < n; i++)
            if(A[i])
                cout << i << " ";
        cout << endl;
        return;
    }
    A[cur] = 1;
    print_subset(n, A, cur + 1);
    A[cur] = 0;
    print_subset(n, A, cur + 1);
}

int main() {
    int n;
    while(scanf("%d", &n)) {
        int A[n];
        print_subset(n, A, 0);
    }
    return 0;
}
