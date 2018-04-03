#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(0 == strs.size())
            return "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string end = strs[strs.size() - 1];
        int i = 0;
        for(; i < first.size(); i++) {
            if(first[i] != end[i])
                break;
        }
        return first.substr(0, i);
    }
};

int main() {
    Solution s;
    vector<string> str;
    str.push_back("abcd");
    str.push_back("abc");
    str.push_back("abcd");
    cout << s.longestCommonPrefix(str) << endl;
}
