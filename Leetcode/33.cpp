#include<iostream>
#include<cstdio>
#include<sstream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

string str1, str2, t;
vector<string> arr;
int minx = 0x7FFFFFFF;
int cur = 0;

bool isDiffOneChar(const string &s1, const string &s2) {
    int diff = 0;
    for(int i=0; i<s1.size(); i++)
        if(s1[i] != s2[i])
            diff++;
    return diff == 1 ? true : false;
}

void dfs(string s1, string s2, int flag[]) {
    if(s1 == s2) {
        if(cur < minx) {
            minx = cur;
            cur = 0;
        }
        return;
    }
    for(int i=0; i<arr.size(); i++) {
        if(flag[i] == 1)
            continue;
        if(isDiffOneChar(arr[i], s1)) {
            flag[i] = 1;
            cur++;
            dfs(arr[i], s2, flag);
            flag[i] = 0;
        }
    }
}

int main() {
    cin >> str1 >> str2;
    getchar();
    char s[1000];
    gets(s);
    stringstream ss(s);
    while(ss >> t)
        arr.push_back(t);
    int flag[t.size()];
    memset(flag, 0, sizeof(flag));
    dfs(str1, str2, flag);
    cout << minx << endl;
    return 0;
}
