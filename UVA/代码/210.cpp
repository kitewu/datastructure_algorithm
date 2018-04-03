#include<iostream>
#include<deque>
#include<queue>
#include<string>
#include<sstream>
#include<map>
using namespace std;

typedef struct {
    queue<string> task;
}Program;

typedef struct Var{
    int value;
    bool lock;
    Var(int v = 0) : lock(false){}
}Var;

int main(){
    map<string, Var> vars;//保存变量
    deque<Program> pros;//保存程序
    int n, Q, time[5];

    cin >> n;
    for(int i = 0; i < 5; i++) cin >> time[i];
    cin >> Q;
    string line;
    for(int i = 0; i < n; i++){
        Program pro;
        while(cin >> line){
            if(line == "end")
                break;
            if(line.find_first_of('=') != line.npos){
                stringstream ss(line);
                int v; string name, e;
                ss >> name >> e >> v;
                vars[name] = Var(v);
            }
            pro.task.push(line);
        }
        pros.push_back(pro);
    }
}
