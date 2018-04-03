#include<iostream>
#include<cstring>
using namespace std;

bool check(long long n){
    int arr[10];
    memset(arr, 0 , sizeof(arr));
    while(n){
        arr[n%10]++;
        n /= 10;
    }
    for(int i=0; i<=9; i++){
        if(arr[i] != 1)
            return false;
    }
    return true;
}

int main(){
    cout << 6159 * 6159 * 6159 << endl;
    for(int i=1; i<10000; i++){
        if(check(i*i*i)){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
