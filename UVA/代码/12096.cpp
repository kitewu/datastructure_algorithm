#include<iostream>
#include<stdio.h>
#include<set>
#include<stack>
#include<algorithm>
#include<map>
#include<vector>
#include<iterator>
#define Set set<int>
using namespace std;

map<Set, int> mmap;
vector<Set> mvec;

int getID(Set mset) {
    if(mmap.count(mset))
        return mmap[mset];
    mvec.push_back(mset);
    int pos = mvec.size() - 1;
    mmap[mset] = pos;
    return pos;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        getchar();
        string op;
        stack<int> mst;
        mmap.clear();
        mvec.clear();
        while(m--) {
            cin >> op;
            int id = 0;
            if(op == "PUSH") {
                mst.push(getID(Set()));
                id = 0;
            } else if(op == "DUP") {
                id = getID(mvec[mst.top()]);
                mst.push(id);
            } else {
                int s1 = mst.top();mst.pop();
                int s2 = mst.top();mst.pop();
                Set temp;
                if(op == "ADD") {
                    temp = mvec[s2];
                    temp.insert(s1);
                    id = getID(temp);
                    mst.push(id);
                } else if(op == "UNION") {
                    set_union(mvec[s1].begin(), mvec[s1].end(), mvec[s2].begin(), mvec[s2].end(), inserter(temp, temp.begin()));
                    id = getID(temp);
                    mst.push(id);
                } else if(op == "INTERSECT") {
                    set_intersection(mvec[s1].begin(), mvec[s1].end(), mvec[s2].begin(), mvec[s2].end(), inserter(temp, temp.begin()));
                    id = getID(temp);
                    mst.push(id);
                }
            }
            cout << mvec[id].size() << endl;
        }
        cout << "***" << endl;
    }
}
