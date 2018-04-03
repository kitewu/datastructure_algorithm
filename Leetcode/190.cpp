#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result += n & 1;
            n >>= 1;
            if (i < 31) {
                result <<= 1;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits(2);
    return 0;
}

