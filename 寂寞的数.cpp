#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 11000;

int main(){
    int n;
    cin >> n;
    int arr[maxn];
    memset(arr, 0, sizeof(int) * (maxn));
    for(int i = 1; i <= 10000; i++){
        int pos = i;
        int temp = i;
        while(temp){
            pos += temp % 10;
            temp /= 10;
        }
        arr[pos] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(0 == arr[i])
            cout << i << endl;
    }
    return 0;
}
