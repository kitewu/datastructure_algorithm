#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;
typedef long long ll;

class Solution {
public:
    int reverse(int x) {
        int original = x;
        long long int r = 0;
        while(x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        if(r > 2147483647ll || r < -2147483648ll)
            return 0;
        return (int)r;
    }
};

int main() {
    Solution s;
    printf("%d", s.reverse(-1235));
}
