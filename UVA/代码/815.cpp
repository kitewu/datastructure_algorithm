#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
int main() {
    int m, n, T = 0;
    while (true) {
        cin >> m >> n;
        if (!m && !n)
            break;
        multiset<int> se;
        int len = m * n, total, t;
        for (int i = 0; i < len; i++) {
            cin >> t;
            se.insert(t);
        }
        cin >> total;
        multiset<int>::iterator it = se.begin();
        int a[len], b[len], j = 1;
        a[0] = *it;
        b[0] = 0;
        it++;
        for (; it != se.end(); it++) {
            a[j] = *it;
            b[j] = a[j] - a[j - 1];
            j++;
        }
        int sum = 0, pos = 1;
        bool flag = false;
        for (; pos < len; pos++) {
            sum += b[pos] * pos;
            if (sum * 100 >= total) {
                flag = true;
                break;
            }
        }
        if (flag) sum -= b[pos] * pos;
        int re = total - sum * 100;
        double level = a[pos - 1] + re * 1.0 / (pos * 100);
        printf("Region %d\nWater level is %.2lf meters.\n", ++T, level);
        printf("%.2lf percent of the region is under water.\n\n",
               pos * 100.0 / len);
    }
    return 0;
}
