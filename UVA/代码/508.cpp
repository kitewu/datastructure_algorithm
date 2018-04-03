#include<iostream>
#include<sstream>
#include<string>
#include<map>
#define CSmap map<char, string>
#define SSmap map<string, string>
using namespace std;

CSmap mmap;
SSmap dic;

int getMinDiff(string a, string b){
    if(a == b)
        return 0;
    if(a.size() > b.size())
        swap(a, b);
    if(a == b.substr(0, a.size()))
        return b.size() - a.size();
    else
       return 10000;
}

string solve(string code){
    int minn = 10000;
    string result;
    for(SSmap::iterator it = dic.begin(); it != dic.end(); it++){
        int t = getMinDiff(it->second, code);
        if(minn > t){
            minn = t;
            result = it->first;
        }
        else if(minn == 0 && t == 0 && result[result.size() - 1] != '!'){
            result += '!';
        }
    }
    if(minn)
        result += '?';
    return result;
}

int main(){

    char c;
    string str;
    while(cin >> c){
        if(c == '*')
            break;
        cin >> mmap[c];
    }
    while(cin >> str){
        if(str[0] == '*')
            break;
        string morse = "";
        for(int i = 0; i < str.size(); i++)
            morse += mmap[str[i]];
        dic[str] = morse;
    }
    while(cin >> str){
        if(str[0] == '*')
            break;
        cout << solve(str) << endl;
    }
    return 0;
}
