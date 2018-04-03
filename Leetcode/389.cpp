#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[2][26];
        memset(arr, 0, sizeof(int)*2*26);
        for(int i=0 ; i<t.length(); i++)
            arr[0][t[i]-'a']++;
        for(int i=0; i<s.length(); i++)
            arr[1][s[i]-'a']++;
        char res;
        for(int i=0; i<26; i++) {
            if(arr[0][i] != arr[1][i]) {
                res = i+'a';
                return res;
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.findTheDifference("abcd", "abcde");
    return 0;
}
