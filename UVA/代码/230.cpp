#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
int main() {
    map<string, set<string> > au_tis;//作者-书名集合
    map<string, string> ti_au;//书名到作者
    string str;
    while(getline(cin , str)) {
        if(str == "END")
            break;
        int pos = str.find_last_of("\"") + 1;
        string ti = str.substr(0, pos);
        string au = str.substr(pos + 4);
        au_tis[au].insert(ti);
        ti_au[ti] = au;
    }
    string op;
    while(cin >> op) {
        if(op == "END")
            break;
        string bname;
        cin >> bname;
        if(op[0] == 'B') {
            au_ti[ti_au[bname]].erase(bname);
            ti_au[bname].erase();
        } else if(op[0] == 'R') {

        } else if(op[0] == 'S') {

        }
    }
//    for(map<string, set<string> >::iterator it = maps.begin(); it != maps.end(); it++){
//        cout << it->first << endl;
//        for(set<string>::iterator ii = it->second.begin(); ii != it->second.end(); ii++){
//            cout << *ii << endl;
//        }
//    }
}
