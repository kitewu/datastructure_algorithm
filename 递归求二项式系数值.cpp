#include<iostream>
#define ll long long
using namespace std;
ll cal(int k, int n){
    if(k == 0 || k == n)
        return 1;
    else
        return cal(k, n - 1) + cal(k - 1, n - 1);
}
int main(){
    int n, k;
    cin >> k >> n;
    cout << cal(k, n);
    return 0;
}
