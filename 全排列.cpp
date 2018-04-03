#include<iostream>
#include<vector>

using namespace std;

///保存中间结果
vector<char> path;

///保存所有结果
vector<vector<char> > result;

void dfs(vector<char>& vv, int step, int flag[]) {
    if(step == vv.size()) {
//        for(int i=0; i<path.size(); i++)
//            cout << path[i] << " ";
//        cout << endl;
        result.push_back(path);
        return;
    }
    for(int i=0; i<vv.size(); i++) {
        if(flag[i] == 0) {
            flag[i] = 1;
            path.push_back(vv[i]);
            dfs(vv, step+1, flag);
            path.pop_back();
            flag[i] = 0;
        }
    }
}

int main() {
    vector<char> v;
    for(int i=0; i<3; i++)
        v.push_back('o' + i);

    ///标志位
    int flag[v.size()];
    memset(flag, 0, sizeof(flag));

    dfs(v, 0, flag);

    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
