#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        int i = 0;
        while(str[i] && str[i] == ' ') i++;
        if(!str[i])
            return 0;
        bool poss = true;
        if(str[i] == '+') i++;
        else if(str[i] == '-'){
            i++;
            poss = false;
        }
        long long int result = 0;
        while(str[i] != 0){
            int num = str[i] - '0';
            if(num > 9 || num < 0)
                return poss ? result : result * -1;
            result = result * 10 + num;
            if(result > 2147483647ll || result < -2147483648ll)
                return poss ? (int)0x7FFFFFFF : (int)0x80000000;
            i++;
        }
        return poss ? (int)result : (int)result * -1;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("123");
}
