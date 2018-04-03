#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 200;
int a[maxn];

void build(int pos) {
    int v;
    cin >> v;
    if(v == -1)
        return;
    a[pos] += v;
    build(pos - 1);
    build(pos + 1);
}

bool init() {

    int v;
    cin >> v;
    if(v == -1)
        return false;
    memset(a, 0, sizeof(a));
    int pos = maxn / 2;
    a[pos] = v;
    build(pos - 1);
    build(pos + 1);
    return true;
}

int main() {
    int N = 0;
    while(init()) {
        int p = 0;
        while(!a[p]) p++;
        cout << "Case " << ++N << ":\n" << a[p++];
        while(a[p]) cout << " " << a[p++];
        cout << "\n\n";
    }
}
