#include<iostream>
#include<vector>

using namespace std;

int CompactIntegers(vector<int> &vv, int n) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(0 != vv[i])
            vv[j++] = vv[i];
    }
    cout << j << endl;
    for(int i = 0; i < j; i++){
        if(i == 0)
            cout << vv[i];
        else
            cout << " " << vv[i];
    }
    cout << endl;
    return j;
}

int main() {
    int n;
    cin >> n;
    vector<int> vv(n);
    for(int i = 0; i < n; i++)
        cin >> vv[i];
    CompactIntegers(vv, n);
    return 0;
}
