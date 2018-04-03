#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int x;
    for(x = 1; x <= N; x++){
        int time, gift_num;
        queue<int> qu;
        cin >> time >> gift_num;
        cout << "Case #" << x << ":" << endl;
        for(int i = 0; i < time; i++){
            int op;
            cin >> op;
            if(op == 0){
                int xx = gift_num < qu.size() ?  gift_num : qu.size();
                cout << gift_num;
                for(int jj = 0; jj < xx; jj++){
                    cout << " " << qu.front();
                    qu.pop();
                    gift_num--;
                }
            }

            if(op > 0){
                for(int j = 0; j < op; j++){
                    int t;
                    cin >> t;
                    qu.push(t);
                }
            }

            if(op < 0){
                int t;
                cin >> t;
                gift_num+=(-t);
            }
        }
    }
}
