#include<iostream>

using namespace std;

int main(){
    int n, a[2] = {1, 1};
    cin >> n;
    int i = 3;
    for(; i <= n; i++){
        a[i % 2] = (a[0] + a[1]) % 10007;
    }
    cout << a[(i - 1) % 2] << endl;
    return 0;
}
