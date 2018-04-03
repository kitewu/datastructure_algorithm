#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n + 1];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    for(int i = 0; i < n; i++) {
        if(target == arr[i]) {
            cout << ++i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}

