#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct face {
    int x, y;
} a[6];

bool check() {
    if(memcmp(a, a+1, sizeof(face)) || memcmp(a+2, a+3, sizeof(face)) || memcmp(a+4, a+5, sizeof(face))) return false;
    if(a[0].x!=a[2].x || a[0].y!= a[4].x || a[2].y!=a[4].y) return false;
    return true;
}

int compare(struct face a, struct face b) {
    if(a.x > b.x)
        return 1;
    else if(a.x == b.x)
        if(a.y > b.y)
            return 1;
        else if(a.y == b.y)
            return 0;
        else
            return -1;
    else
        return -1;
}

void msort() {
    for (int i = 6 - 1; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (compare(a[j + 1], a[j]) < 0) {
                struct face temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int main() {
    while(cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y >> a[4].x >> a[4].y >> a[5].x >> a[5].y) {
        for(int i = 0; i < 6; ++i)
            if(a[i].x > a[i].y)
                swap(a[i].x, a[i].y);
        msort();
        printf("%s\n", check() ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}
