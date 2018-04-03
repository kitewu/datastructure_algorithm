#include<iostream>
#include<vector>

using namespace std;

vector<char> path(10, -1);
int flag[10];

void dfs(int step) {
    if(step == 11) {
//        for(int i=0; i<path.size(); i++)
//            cout << path[i] << " ";
//        cout << endl;

        return;
    }
    for(int i=0; i<10; i++) {
        if(flag[i] == 0) {
            int can = true;
            if(step == 2) {
                if(path[6]+1==2 || path[6]-1==2)
                    can = false;
            } else if(step == 3) {
                if(path[4]+1==3 || path[4]-1==3 || path[7]+1==3 || path[7]-1==3)
                    can = false;
            } else if(step == 4) {

            } else if(step == 5 || step == 6) {
            } else if(step == 7) {
            } else if(step == 8) {
            } else if(step == 9) {
            } else if(step == 10) {
            }
            flag[i] = 1;
            path.push_back(vv[i]);
            dfs(step+1);
            path.pop_back();
            flag[i] = 0;
        }
    }
}

int main() {
    dfs(0);
}

