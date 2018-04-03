#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int max = abs(v[1] - v[0]);
    for(int i = 1; i < n; i++){
        int c = abs(v[i] - v[i-1]);
        if(c >= max)
            max = c;
    }
    cout << max << endl;
    return 0;
}
