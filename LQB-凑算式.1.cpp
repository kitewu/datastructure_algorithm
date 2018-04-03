#include<iostream>
#include<vector>
using namespace std;

int book[10];
int flag[10];

void dfs(int step, vector<int> v) {
    if(step == 10) {
        for(int i=1; i<=10; i++)
            if(flag[i] > 1)
                return;
        for(int i=1; i<=10; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    for(int i=step; i<=v.size(); i++) {
        if(book[i] == 0) {
            book[i] = 1;
            flag[i]++;

            v.push_back(i);

            flag[i]--;
            book[i] = 0;
        }
    }
}

int main() {
    vector<int> v;
    for(int i=1; i<=9; i++)
        v.push_back(i);
    dfs(1, v);
    return 0;
}
