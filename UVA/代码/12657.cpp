#include<stdio.h>
#include<list>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    int X = 1;
    while(scanf("%d%d", &n, &m) == 2) {
        list<int> li;
        int a, x, y;
        bool right = true;
        list<int>::iterator itx, ity, itt;
        list<int>::reverse_iterator ritx, rity, ritt;
        for(int i = 1; i <= n; i++)
            li.push_back(i);
        while(m--) {
            scanf("%d", &a);
            if(a == 4) right = !right;
            else {
                scanf("%d%d", &x, &y);
                itx = find(li.begin(), li.end(), x);
                ity = find(li.begin(), li.end(), y);
                if(a == 1) {
                    itt = ity;
                    if(right) {
                        itt--;
                        if(ity == li.begin() || itt != itx) {
                            li.insert(ity, x);
                            li.erase(itx);
                        }
                    } else {
                        itt++;
                        if(itt == li.end() || itt != itx) {
                            li.insert(itt, x);
                            li.erase(itx);
                        }
                    }
                } else if(a == 2) {
                    itt = ity;
                    if(right) {
                        itt++;
                        if(itt == li.end() || itt != itx) {
                            li.insert(itt, x);
                            li.erase(itx);
                        }
                    } else {
                        itt--;
                        if(ity == li.begin() || itt != itx) {
                            li.insert(ity, x);
                            li.erase(itx);
                        }
                    }
                } else if(a == 3) {
                    *itx = y;
                    *ity = x;
                }
            }
        }
        long long int sum = 0;
        int flag = 1;
        if(right)
            for(itx = li.begin(); itx != li.end(); itx ++) {
                if(flag) {
                    sum += *itx;
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
        else
            for(ritx = li.rbegin(); ritx != li.rend(); ritx++) {
                if(flag) {
                    sum += *ritx;
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
        printf("Case %d: %lld\n",X++, sum);
    }
    return 0;
}

