#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        int begin = 0, end = s.size()-1;
        while(s[begin] == ' ' && begin < end) begin++;
        while(s[end] == ' ' && begin < end) end--;
        s = s.substr(begin, end);

        if(s.empty())
            return false;

        if((s[0] < '0' || s[0] > '9') && s.size() == 1)
            return false;
        int point = 0;

        if(s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9') || s[0] == '.') {
            if(s[0] == '.')
                point++;
            for(int i=1; i<s.size(); i++) {
                if(s[i] >= '0' && s[i] <= '9') {
                    continue;
                } else if(s[i] == '.') {
                    point++;
                    if(point>1)
                        return false;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    string str;
    while(cin >> str)
        cout << s.isNumber(str) << endl;
}
