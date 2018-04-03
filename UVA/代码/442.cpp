#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

struct Mutrix {
    int a, b;
    Mutrix(int a = 0, int b = 0):a(a), b(b) {}
} m[26];

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    while(N--) {
        char c;
        int a, b;
        scanf("%c%d%d", &c, &a, &b);
        m[c - 'A'].a = a;
        m[c - 'A'].b = b;
        getchar();
    }
    string str;
    while(cin >> str) {
        stack<Mutrix> sta;
        int len = str.length();
        int sum = 0;
        bool ok = true;
        if(len != 1) {
            for(int i = 0; i < len; i++) {
                if(str[i] >= 'A' && str[i] <= 'Z') {
                    sta.push(m[str[i] - 'A']);
                } else if(str[i] == ')') {
                    Mutrix t2 = sta.top();
                    sta.pop();
                    Mutrix t1 = sta.top();
                    sta.pop();
                    if(t1.b != t2.a) {
                        ok = false;
                        break;
                    } else {
                        sum += t1.a * t1.b * t2.b;
                        sta.push(Mutrix(t1.a, t2.b));
                    }
                }
            }
        }
        if(ok)
            printf("%d\n", sum);
        else
            printf("error\n");
    }
    return 0;
}
