#include<iostream>
#include<cctype>
#include<string>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        char c[S.length()+1];
        int len = 0;
        for(int i=0; i<S.length(); i++)
            if(S[i] != '-')
                c[len++] = toupper(S[i]);
        c[len] = 0;
        string newstr(c);

        if(K > newstr.length())
            return newstr;

        int start = newstr.length() % K;
        if(start == 0)
            start = K;
        string res = newstr.substr(0, start);
        int n = (newstr.length()-start) / K;
        for(int i=start; i<len; i+=K)
            res += "-" + newstr.substr(i, K);
        return res;
    }
};

int main(){
    Solution s;
    cout << s.licenseKeyFormatting("2-4A0r7-4k", 4);
    return 0;
}

