#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool flag = true;
    int mid = n / 2;
    int i = mid;
    int j = (n&1) ? i : i - 1;
    for(; i < n, j >= 0; i++, j--) {
        if((a[i] != a[mid] && a[j] == a[mid]) || (a[i] == a[mid] && a[j] != a[mid])) {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << a[n / 2] << endl;
    else
        cout << -1;
    return 0;
}
