#include<algorithm>
#include<iostream>
using namespace std;

int a[505], b[505];

int main() {
    int n, r, sum=0;
    cin >> n >> r;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(int i=0; i<r; i++)
        b[i] = a[i];
    for(int i=r; i<n; i++)
        b[i] = b[i-r] + a[i];
    for(int i=0; i<n; i++)
        sum += b[i];
    cout << sum << endl;
    return 0;
}
