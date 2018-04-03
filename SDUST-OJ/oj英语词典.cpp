#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    string str;
    set<string> se;
    set<string>::iterator it;
    while(cin >> str){
        se.insert(str);
    }
    for(it = se.begin(); it != se.end(); it++){
        cout << *it << endl;
    }
}
