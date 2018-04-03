#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int func(string str1, string str2) {
        if(str1.length() != str2.length())
            return false;
        string str3 = str2 + str2;
        return str3.find(str1);
    }
};

int main() {
    Solution s;
    cout << s.func("1234", "2345623456");
    return 0;
}

