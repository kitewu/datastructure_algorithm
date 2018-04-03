#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i = 1;i <= N;i++){
        queue<string> qu[15];
        cout << "Case #" << i << " :" <<endl;
        int n, m;
        cin >> n >> m;
        int op;
        for(int j = 1; j <= m; j++){
            cin >> op;
            if(op == 0){
                int a, k;
                cin >> a >> k;
                while(k--){
                    cout << qu[a].front() << endl;
                    qu[a].pop();
                }
            }
            else if(op == 1){
                string a;
                int y;
                cin >> a >> y;
                qu[y].push(a);
            }
            else if(op == 2){
                int a;
                cin >> a;
                cout << qu[a].size() << endl;
            }
        }

    }
}
