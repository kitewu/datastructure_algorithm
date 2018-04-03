#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0)
            break;
        vector<vector<int> > vv(n+1);
        int flag[n+1];
        memset(flag, 0, sizeof(flag));
        int a, b;
        for(int i=0; i<m; i++) {
            cin >> a >> b;
            if(a > b) {
                a=a^b;
                b=a^b;
                a=a^b;
            }
            vv[a].push_back(b);
        }
        if(vv[1].size() == 0)
            cout << 0 << endl;
        else {
            int sum = 0;
            queue<int> que;
            que.push(1);
            flag[1] = 1;
            while(!que.empty()) {
                int top = que.front();
                que.pop();
                if(!vv[top].empty()) {
                    for(int j=0; j<vv[top].size(); j++) {
                        if(flag[vv[top][j]] == 0) {
                            flag[vv[top][j]] = 1;
                            sum++;
                            que.push(vv[top][j]);
                        }
                    }
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}
