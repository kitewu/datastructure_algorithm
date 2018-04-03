#include<iostream>
#include<queue>
using namespace std;
int main() {
    int N;
    cin >> N;
    queue<int> que;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            cin >> b;
            que.push(b);
        } else if(a == 2) {
            if(que.size() != 0) {
                cout << que.front() << endl;
                que.pop();
            } else {
                cout << "no" << endl;
                break;
            }
        } else if(a == 3) {
            cout << que.size() << endl;
        }
    }
    return 0;
}
