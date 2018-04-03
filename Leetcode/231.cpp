#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && ((n&(n-1)) == 0);
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfTwo(2);
    return 0;
}
