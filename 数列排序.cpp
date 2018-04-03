#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int len, v;
    vector<int>vec;
    cin >> len;
    for(int i = 0; i < len; i++){
        cin >> v;
        vec.push_back(v);
    }
    sort(vec.begin(), vec.end());
    cout << vec[0];
    for(int i = 1; i < len; i++){
        cout << " " << vec[i];
    }
    return 0;
}
