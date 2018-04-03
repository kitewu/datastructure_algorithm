#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

class node{
public:
    node(int a = 0, int b = 0):a(a), b(b){}
    void setValue(int ta, int tb){a = ta, b = tb;}
    int a, b;
};

struct cmp{
    bool operator()(const node& A, const node& B){
        if(A.a < B.a)
            return true;
        else if(A.a > B.a)
            return false;
        else
            return A.b < B.b;
    }
};

bool cmp1(const node& A, const node& B){
	if(A.a < B.a)
            return true;
        else if(A.a > B.a)
            return false;
        else
            return A.b < B.b;
}

int main()
{
    node nd[3];
    nd[0].setValue(1,2);
    nd[1].setValue(2,2);
    nd[2].setValue(1,1);
    sort(nd, nd + 3, cmp1);
    int len = sizeof(nd) / sizeof(node);
    for(int i = 0; i < len; i++)
        cout << nd[i].a << " " << nd[i].b << endl;
    return 0;
}

