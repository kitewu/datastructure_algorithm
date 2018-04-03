#include<cstdio>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int xx = x;
        int len = 1;
        while(xx /= 10) len *= 10;
        while(x){
            int left = x / len;
            int right = x % 10;
            if(left != right)
                return false;
            x = (x % len) / 10;
            len /= 100;
        }
        return true;

//        stringstream ss;
//        ss << x;
//        string str;
//        ss >> str;
//        for(int i = 0, j = str.size() - 1; i <= j; i++ , j--){
//            if(str[i] != str[j])
//                return false;
//        }
//        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(12345);
}
