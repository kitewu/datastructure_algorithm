#include<iostream>
#include<stdio.h>
#include<set>
#include<string>
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
    int N;
    while(cin >> N) {
        getchar();
        set<string> se;
        int mlen = 0;
        for(int x = 0; x < N; x++){
            string str;
            cin >> str;
            se.insert(str);
            if(str.size() > mlen) mlen = str.size();
        }
        int col = (60 - mlen) / (mlen + 2) + 1;
        int row = ceil(N * 1.0 / col);
        string vv[row][col];
        set<string>::iterator it = se.begin();
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                if(it == se.end())
                    goto loop;
                vv[j][i] = *it;
                it++;
            }
        }
loop:
        cout << "------------------------------------------------------------" << endl;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(j == col - 1)
                    cout << left << setfill(' ') << setw(mlen) << vv[i][j];
                else
                    cout << left << setfill(' ') << setw(mlen + 2) << vv[i][j];
            }
            cout << endl;
        }
    }
}
