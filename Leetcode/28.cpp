#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = haystack.find(needle);
        return string::npos == ans ? -1 : ans;
    }
};

int main() {
    Solution s;
    cout << s.strStr("1123456", "123");
}
