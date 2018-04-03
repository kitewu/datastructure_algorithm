#include<iostream>
#include<set>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string str;
    set<string> s;
    set<string>:: iterator it;
    while(getline(cin, str)){
        string t;
        for(int i = 0; i < str.length(); i++){
            if(isalpha(str[i])){
                t += tolower(str[i]);
            }else{
                if(t.length() != 0)
                s.insert(t);
                t.clear();
            }
        }
    }
    for(it = s.begin(); it != s.end(); it++){
        if(it != s.begin()){
            cout << endl;
        }
        cout << *it;
    }
}
