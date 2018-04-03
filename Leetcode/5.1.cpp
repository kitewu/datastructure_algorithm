#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        if(len <= 1)return s;

        string str = preProcess(s);
        int n = str.size(), id = 0, mx = 0;
        vector<int> p(n, 0);
        for(int i = 1; i < n - 1; i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while(str[i + p[i]] == str[i - p[i]])
                p[i]++;
            if(i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }

        //遍历p，寻找最大回文长度
        int maxLen = 0, index = 0;
        for(int i = 1; i < n-1; i++)
            if(p[i] > maxLen) {
                maxLen = p[i];
                index = i;
            }
        return s.substr((index - maxLen) / 2, maxLen - 1);
    }
    //预处理字符串，abc预处理后变成$#a#b#c#^
    string preProcess(const string &s) {
        int n = s.size();
        string res;
        res.push_back('$');//把$放到字符串头部
        res.push_back('#');//以#作为原来字符串中每个字符的间隔
        for(int i = 0; i < n; i++) {
            res.push_back(s[i]);
            res.push_back('#');
        }
        res.push_back('^');//以^作为字符串的结尾
        return res;
    }
};

int main() {

}

