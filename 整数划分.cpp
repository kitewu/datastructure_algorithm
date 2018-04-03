#include<iostream>
#include<vector>

using namespace std;

int total = 0;

void dfs(int step, int n){
    if(n < 0)
        return;
    if(0 == n){
        total++;
        return;
    }
    for(int i=step; i<=n; i++){
        dfs(i, n-i);
    }
}

int main(){
    int n;
    cin >> n;
    dfs(1, n);
    cout << total << endl;
    return 0;
}

