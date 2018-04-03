#include<iostream>
#include<map>
#include<string>
#include<stdio.h>
#include<vector>
#include<sstream>
#define Map map<string, string>
using namespace std;

//´´½¨×Öµä
void getKeyAndValue(string sub, Map&mmap) {
    for(int i = 0; i < sub.size(); i++) {
        if(sub[i] == ',' || sub[i] == ':')
            sub[i] = ' ';
    }
    stringstream ss(sub);
    string key, value;
    while(ss >> key >> value)
        mmap[key] = value;
}

void show(char c, Map &mmap) {
    for(Map::iterator it = mmap.begin(); it != mmap.end(); it++) {
        if(it == mmap.begin())
            cout << c << it->first;
        else
            cout << "," << it->first;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str1, str2;
        Map map1, map2;
        vector<string> vv;
        cin >> str1 >> str2;
        getKeyAndValue(str1.substr(1, str1.size() - 2), map1);
        getKeyAndValue(str2.substr(1, str2.size() - 2), map2);
        if(map1 == map2) {
            cout << "No changes" << endl << endl;
            continue;
        }
        Map::iterator it1 = map1.begin();
        Map::iterator it2 = map2.begin();
        while (it1 != map1.end() && it2 != map2.end()) {
            if (it1->first == it2->first) {
                if (it1->second != it2->second)
                    vv.push_back(it1->first);
                map1.erase(it1++);
                map2.erase(it2++);
            } else if (it1->first < it2->first)
                it1++;
            else if (it1->first > it2->first)
                it2++;
        }
        if(!map2.empty()) show('+', map2);
        if(!map1.empty()) show('-', map1);
        for (int i = 0; i < vv.size(); i++) {
            if (!i)  cout << "*" << vv[i];
            else cout << "," << vv[i];
        }
        if (vv.size())  cout << endl;
        cout << endl;
    }
    return 0;
}
