#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<sstream>
#include<iterator>
#include<set>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int N, m;
int lines = 0;
map<string, set<int> > maps;
string allline[1510];
int linehash[1510];
set<int> allset;

void Show(set<int> &se) {
    int tt = -1;
    bool flag = false;
    for(set<int>::iterator it = se.begin(); it != se.end(); it++) {
        if(linehash[*it] != tt) {
            if(flag)
                cout << "----------" << endl;
            flag = true;
        }
        cout << allline[*it] << endl;
        tt = linehash[*it];
    }
}

//not
void Show2(set<int> &se) {
    bool flag = false;
    for(int i = 0; i < lines; ) {
        if(se.count(linehash[i]) > 0) {
            if(flag) {
                cout << "----------" << endl;
            }
            flag = true;
            int nn = linehash[i];
            for(; i < lines && linehash[i] == nn; i++)
                cout << allline[i] << endl;
        } else {
            int nn = linehash[i];
            for(; i < lines && linehash[i] == nn; i++);
        }
    }
}

//and
void Show3(set<int> &se, set<int> &se1, set<int> &se2) {
    set<int> temp_set;
    set_union(se1.begin(), se1.end(), se2.begin(), se2.end(), inserter(temp_set, temp_set.begin()));
    bool flag = false;
    int tt = -1;
    for(set<int>::iterator it = temp_set.begin(); it != temp_set.end(); it++) {
        if(se.count(linehash[*it]) > 0) {
            if(tt != linehash[*it]) {
                if(flag)
                    cout << "----------" << endl;
                flag = true;
            }
            cout << allline[*it] << endl;
            tt = linehash[*it];
        }
    }
}

void getAllSet() {
    for(int i = 0; i < lines; i++)
        allset.insert(i);
}

void input() {
    scanf("%d", &N);
    getchar();
    string s, buf;
    for(int i = 0; i < N; i++) {
        while(getline(cin ,s)) {
            if(s == "**********")
                break;
            allline[lines] = s;
            for(int k = 0; k < s.length(); k++)
                if(isalpha(s[k]))
                    s[k] = tolower(s[k]);
                else
                    s[k] = ' ';
            stringstream ss(s);
            while(ss >> buf)
                maps[buf].insert(lines);
            linehash[lines] = i;
            lines++;
        }
    }
}

int main() {
    input();
    getAllSet();
    scanf("%d", &m);
    getchar();
    string s, buf;
    while(m--) {
        getline(cin ,s);
        vector<string> v;
        stringstream ss(s);
        while(ss >> buf)
            v.push_back(buf);
        if(v.size() == 1) {
            if(!maps[v[0]].empty())
                Show(maps[v[0]]);
            else
                cout << "Sorry, I found nothing." << endl;
        } else if(v[1] == "AND") {
            set<int> se1;
            set<int> se2;
            for(set<int>::iterator it = maps[v[0]].begin(); it != maps[v[0]].end(); it++)
                se1.insert(linehash[*it]);
            for(set<int>::iterator it = maps[v[2]].begin(); it != maps[v[2]].end(); it++)
                se2.insert(linehash[*it]);
            set<int> temp_set;
            set_intersection(se2.begin(), se2.end(), se1.begin(), se1.end(), inserter(temp_set, temp_set.begin()));
            if(temp_set.size() != 0)
                Show3(temp_set, maps[v[0]], maps[v[2]]);
            else
                cout << "Sorry, I found nothing." << endl;
        } else if(v[1] == "OR") {
            set<int> temp_set;
            set_union(maps[v[0]].begin(), maps[v[0]].end(), maps[v[2]].begin(), maps[v[2]].end(), inserter(temp_set, temp_set.begin()));
            if(temp_set.size() != 0)
                Show(temp_set);
            else
                cout << "Sorry, I found nothing." << endl;
        } else {//not
            set<int> se1;
            set<int> se2;
            for(int i = 0; i < N; i++) se2.insert(i);
            for(set<int>::iterator it = maps[v[1]].begin(); it != maps[v[1]].end(); it++)
                se1.insert(linehash[*it]);
            set<int> temp_set;
            set_difference(se2.begin(), se2.end(), se1.begin(), se1.end(), inserter(temp_set, temp_set.begin()));
            if(temp_set.size() != 0)
                Show2(temp_set);
            else
                cout << "Sorry, I found nothing." << endl;
        }
        cout << "==========" << endl;
    }
}

