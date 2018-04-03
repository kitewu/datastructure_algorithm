#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        while(s[i] == ' ') i--;
        int begin=i;
        while(i >= 0 && s[i] != ' ') i--;
        return begin-i;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLastWord("   ");
}
