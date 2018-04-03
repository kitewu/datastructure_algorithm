#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m <<= i;
    }
};

int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7);
    return 0;
}
