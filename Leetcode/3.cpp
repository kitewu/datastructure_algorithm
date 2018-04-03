#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256];
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++) {
            memset(arr, 0, sizeof(arr));
            int j = i;
            for(; j < s.length(); j++) {
                if(arr[s[j]] != 0)
                    break;
                arr[s[j]]++;
            }
            if(j - i > maxlen)
                maxlen = j - i;
        }
        return maxlen;
    }
};

int main() {
    Solution s;
    string str = "";
    cout << s.lengthOfLongestSubstring(str) << endl;
    while(cin >> str){
        cout << s.lengthOfLongestSubstring(str) << endl;
    }
}
