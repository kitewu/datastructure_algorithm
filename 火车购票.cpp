#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 20;

struct Seat {
    int emptyCount;//最大连续座位数
    int seat[5];
    Seat() {
        emptyCount = 5;
        memset(seat, 0, 5 * sizeof(int));
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    Seat seat[maxn];
    for(int i = 0; i < n; i++) {
        int need = v[i];
        bool find = false;
        for(int j = 0; j < maxn; j++) {
            if(seat[j].emptyCount >= need){
                int k = 0;
                while(seat[j].seat[k]) k++;
                for(int l = 0; l < need - 1; l++){
                    seat[j].seat[k] = 1;
                    cout << j * 5 + 1 + k << " ";
                    k++;
                }
                seat[j].seat[k] = 1;
                cout << j * 5 + 1 + k << endl;
                seat[j].emptyCount -= need;
                find = true;
                break;
            }
        }
        if(!find){
            vector<int> temp;
            for(int j = 0; j < maxn; j++) {
                if(need == 0)
                    break;
                for(int k = 0; k < 5; k++){
                    if(need == 0)
                        break;
                    if(seat[j].seat[k] == 0){
                        seat[j].seat[k] = 1;
                        seat[j].emptyCount--;
                        need--;
                        temp.push_back(j * 5 + 1 + k);
                    }
                }
            }
            int ff = 0;
            for(; ff < temp.size() - 1; ff++)
                cout << temp[ff] << " " ;
            cout << temp[ff] << endl;
        }
    }
    return 0;
}
