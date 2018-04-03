#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n){
            if(n&1)
                sum++;
            n >>= 1;
        }
        return sum;
    }

    int hammingWeight2(uint32_t n) {
        int sum = 0;
        while(n){
            n &= (n-1);
            sum++;
        }
        return sum;
    }

    int hammingWeight3(uint32_t n) {
        int sum = 0;
        while(n){
            n -= n&(~n+1);
            sum++;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(11);
    return 0;
}
