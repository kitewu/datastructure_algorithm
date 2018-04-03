#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int tmp = 0;
        for (int i = 0; i < s.length(); ++i) {
            tmp = s[i] - 'A' + 1;
            sum = 26 * sum + tmp;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.titleToNumber("AB");
    return 0;
}


