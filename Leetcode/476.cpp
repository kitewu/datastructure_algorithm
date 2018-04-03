#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int temp = num, mask = 1;
        while(temp) {
            temp >>= 1;
            mask <<= 1;
        }
        return ((mask-1) ^ num);
    }
};

int main() {
    Solution s;
    cout << s.findComplement(5);
    return 0;
}
