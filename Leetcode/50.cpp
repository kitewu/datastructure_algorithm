#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        if(n<0) {
            if(n==INT_MIN)
                return 1.0 / (myPow(x, INT_MAX)*x);
            else
                return 1.0/ myPow(x,-n);
        } else {
            if(n%2==0) {
                double tmp = myPow(x, n>>1);
                return tmp * tmp;
            } else {
                double tmp = myPow(x, (n-1)>>1);
                return x*tmp*tmp;
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.myPow(2, -2147483648);
}
