#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:

    int compareVersion(string version1, string version2) {
        if(version1 == version2)
            return 0;
        vector<int> strs1;
        vector<int> strs2;
        getStrings(strs1, version1, 0);
        getStrings(strs2, version2, 0);
        int mmin = min(strs1.size(), strs2.size());
        int i=0;
        for(; i<mmin; i++) {
            if(strs1[i] == strs2[i])
                continue;
            else
                return strs1[i] - strs2[i] > 0 ? 1 : -1;
        }
        if(i<strs1.size()) {
            for(; i<strs1.size(); i++)
                if(strs1[i] > 0)
                    return 1;
        }
        if(i<strs2.size()) {
            for(; i<strs2.size(); i++)
                if(strs2[i] > 0)
                    return -1;
        }
        return 0;
    }

    void getStrings(vector<int> &strs, string str, int begin) {
        int i=begin;
        for(; i<str.length(); i++)
            if(str[i] == '.')
                break;
        strs.push_back(atoi(str.substr(begin, i-begin).c_str()));
        if(i == str.size())
            return;
        getStrings(strs, str, ++i);
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.2.3.4.5.6.7.8.9.10", "1.2.3.4.5.6.7.8.9.1");
    return 0;
}

