#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n) {
            result = (char)((n-1)%26+'A') + result;
            n = (n-1) / 26;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(26);
    return 0;
}


