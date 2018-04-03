#include<stdio.h>
#include<string.h>

int arr[10];

bool judge(int a, int b) {
    if(a > 98765)
        return false;
    if(b < 10000 && a < 10000)
        return false;
    memset(arr, 0, sizeof(arr));
    if(b < 10000 || a < 10000)
        arr[0] = 1;
    int index = 0;
    while(b) {
        index = b % 10;
        if(arr[index] == 1)
            return false;
        arr[index] = 1;
        b /= 10;
    }
    while(a) {
        index = a % 10;
        if(arr[index] == 1)
            return false;
        arr[index] = 1;
        a /= 10;
    }
    return true;
}

int main() {
    int n;
    int count = 0;
    while(scanf("%d", &n) == 1 && n) {
        if(count++)
            printf("\n");
        bool flag = true;
        for(int i = 1234; i <= 98765; i++) {
            if(judge(i * n, i)) {
                printf("%05d / %05d = %d\n", i * n, i, n);
                flag = false;
            }
        }
        if(flag)
            printf("There are no solutions for %d.\n", n);
    }
}
