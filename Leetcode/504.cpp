#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string res;
        string s = "";
        if(num < 0){
            s = "-";
            num *= -1;
        }
        string t = "";
        char c[20];
        while(num){
            string t(itoa(num%7, c, 10));
            res = t + res;
            num /= 7;
        }
        return s + res;
    }
};

int main(){
    Solution s;
    cout << s.convertToBase7(-7);
    return 0;
}
