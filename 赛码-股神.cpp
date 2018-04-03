#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
        if(n == 1)
            cout << 1 << endl;
        else if(n == 2)
            cout << 2 << endl;
        else {
            int a = (-1.0 + sqrt(8*n+1) * 1.0 ) / 2;
            for(int c=1; c>=0; c--) {
                int i = a + c;
                if(n > (i*i-i)/2 && n <= (i*i+i)/2) {
                    int begin = (i*i-i)/2+1;
                    int t = i-3;
                    int sum = (t*t+t)/2+1 + n - begin + 1;
                    if(n == begin + i -1)
                        sum-=2;
                    cout << sum << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

