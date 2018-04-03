#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
#include<algorithm>
#define format(x) left << setfill(' ') << setw(x)
using namespace std;

vector<string> vec[1010];
int N = 0;
int maxcol = 0;
int maxlen[200];

void getMaxLen(){
    for(int j = 0; j < maxcol; j++){
        int len = 0;
        for(int i = 0; i < N; i++)
            if(vec[i].size() > j)
                if(vec[i][j].size() > len)
                    len = vec[i][j].size();
        maxlen[j] = len + 1;
    }
}

int main(){
    string line, buff;
    while(getline(cin, line)){
        stringstream ss(line);
        int tcol = 0;
        while(ss >> buff){
            tcol++;
            vec[N].push_back(buff);
        }
        maxcol = max(maxcol, tcol);
        N++;
    }
    getMaxLen();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < vec[i].size(); j++){
            if(j == vec[i].size() - 1)
                cout << vec[i][j];
            else
                cout << format(maxlen[j]) << vec[i][j];
        }
        cout << endl;
    }
    return 0;
}

/*
  start:   integre;          //  begins here
stop:  integre //  ends here
  S;   string;
c: char; // temp
*/
