#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    bool isVowels(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            while(i<j && !isVowels(s[i])) i++;
            while(i<j && !isVowels(s[j])) j--;
            if(isVowels(s[i]) && isVowels(s[j])){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("leetcode");
    return 0;
}

