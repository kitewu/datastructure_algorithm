#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        return getSum(a^b, (a&b)<<1);
    }
};

int main()
{
    Solution s;
    cout << s.getSum(11, 22);
    return 0;
}
