#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        for(int i=0; i<256; i++)
            last[i] = -1;
        int start = 0;

        int maxlen = 0;
        for(int i=0; i<s.size(); i++) {
            if(last[s[i]] >= start) {
                maxlen = max(i - start, maxlen);
                start = last[s[i]]+1;
            }
            last[s[i]]=i;
        }
        return max((int)s.size() - start, maxlen);
    }
};

int main() {
    Solution s;
    string str = "";
    cout << s.lengthOfLongestSubstring(str) << endl;
    while(cin >> str) {
        cout << s.lengthOfLongestSubstring(str) << endl;
    }
}

