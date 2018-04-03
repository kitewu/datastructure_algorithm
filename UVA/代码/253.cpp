#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        string s1, s2;
        bool same = false;
        s1 = s.substr(0, 6);
        s2 = s.substr(6);
        string t1 = s1.substr(1, 2) + s1.substr(4, 1) + s1.substr(3, 1);
        string t2 = t1;
        swap(t2[1], t2[3]);
        t1 += t1;
        t2 += t2;
        for(int i = 0; i < 4; i++){
            string t = s1.substr(0, 1) + t1.substr(i, 2) + t1.substr(i + 3, 1) + t1.substr(i + 2, 1) + s1.substr(5, 1);
            string tt = s1.substr(0, 1) + t2.substr(i, 1) + t2.substr(i + 3, 1) + t2.substr(i + 1, 2) + s1.substr(5, 1);
            if(t.compare(s2) == 0 || tt.compare(s2) == 0){
                same = true;
                goto loop;
            }
        }
        t1.clear();
        t2.clear();
        t1 = s1.substr(0, 2) + s1.substr(5, 1) + s1.substr(4, 1);
        t2 = t1;
        swap(t2[1], t2[3]);
        t1 += t1;
        t2 += t2;
        for(int i = 0; i < 4; i++){
            string t = t1.substr(i, 2) + s1.substr(2, 2) + t1.substr(i + 3, 1) + t1.substr(i + 2, 1);
            string tt = t2.substr(i, 1) + t2.substr(i + 3, 1) + s1.substr(2, 2) + t2.substr(i + 1, 2);
            if(t.compare(s2) == 0 || tt.compare(s2) == 0){
                same = true;
                goto loop;
            }
        }
        t1.clear();
        t2.clear();
        t1 = s1.substr(0,1) + s1.substr(2,1) + s1.substr(5,1) + s1.substr(3,1);
        t2 = t1;
        swap(t2[1], t2[3]);
        t1 += t1;
        t2 += t2;
        for(int i = 0; i < 4; i++){
            string t = t1.substr(i, 1) + s1.substr(1, 1) + t1.substr(i + 1, 1) + t1.substr(i + 3, 1) + s1.substr(4, 1) + t1.substr(i + 2, 1);
            string tt = t2.substr(i, 1) + s1.substr(1, 1) + t2.substr(i + 3, 1) + t2.substr(i + 1, 1) + s1.substr(4, 1) + t2.substr(i + 2, 1);
            if(t.compare(s2) == 0 || tt.compare(s2) == 0){
                same = true;
                goto loop;
            }
        }
        loop:
        cout << (same ? "TRUE" : "FALSE") << endl;
    }
    return 0;
}
