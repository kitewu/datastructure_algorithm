#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];//输入保证正确
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int result = arr[0];
    int time = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] == result)
            time++;
        else {
            if(--time == 0) {
                result = arr[i];
                time = 1;
            }
        }
    }
    cout << result << endl;
}
