#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        queue<int> qu;
        cout << "Case #" << i << " :" << endl;
        int n, k;
        cin >> n >> k;
        for(int j = 1; j <= n; j++){
            int op;
            cin >> op;
            if(op < 0){
                op = -op;
                k += op;
            }
            else if(op > 0){
                int a;
                for(int t = 1; t <= op; t++){
                    cin >> a;
                    qu.push(a);
                }
            }
            else if(op == 0){
                int c = qu.size();
                if(k > qu.size()){
                    cout << qu.size();
                    while(c--){
                        cout << " " << qu.front();
                        qu.pop();
                        --k;
                    }
                    cout << endl;
                }
                if(k <= qu.size()){
                    cout << k;
                    while(k--){
                        cout << " " << qu.front();
                        qu.pop();
                    }
                    k = 0;
                    cout << endl;
                }
            }
        }
        while(!qu.empty())
            qu.pop();
    }
}
