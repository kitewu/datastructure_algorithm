#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int w, m, n;
    cin >> w >> m >> n;
    int C1, R1;
    R1 = m/w;
    if(m % w == 0)
        R1--;
    C1 = w-1;
    if(R1 & 1) { //奇数，递减
        for(int begin = w * R1 + 1; begin < m; begin++) C1--;
    } else { //偶数，递增
        for(int begin = w * (R1 + 1); begin > m; begin--) C1--;
    }

    int C2, R2;
    R2 = n/w;
    if(n % w == 0)
        R2--;
    C2 = w-1;
    if(R2 & 1) { //奇数，递减
        for(int begin = w * R2 + 1; begin < n; begin++) C2--;
    } else { //偶数，递增
        for(int begin = w * (R2 + 1); begin > n; begin--) C2--;
    }

    cout << R1 << " " << R2 << " " << C1  << " " << C2 << endl;
    cout << abs(1.0*(R1-R2)) + abs(1.0*(C1-C2)) << endl;
}
