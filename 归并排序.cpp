#include<iostream>
using namespace std;

int N = 0x3f3f3f3f;

void merge(int arr[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q+1;
    int left[n1+1], right[n2];
    for(int i=0; i != n1; i++){
        left[i] = arr[p+i];
    }
    left[n1] = N;
    for(int j=0; j!=n2-1; j++){
        right[j] = arr[q+j+1];
    }
    right[n2-1]=N;
    int i=0, j=0;


}

void mergesort(int arr, int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[10] = {2, 5, 4, 6, 7, 89, 5, 3, 5, 7};
    mergesort(arr, 0, 9);
}
