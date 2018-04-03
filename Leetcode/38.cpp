#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0)
            return NULL;
        string ret = "1";
        if(n == 1)
            return ret;
        else {
            for(int i = 2; i <= n; i++)
                ret = countStr(ret);
            return ret;
        }
    }

    string countStr(string str) {
        string ret;
        for(int i= 0; i < str.size(); ) {
            int count = 0;
            char cur_c = str[i];
            while(cur_c == str[i] && i < str.size()) {
                i++;
                count++;
            }
            stringstream ss;
            string scount;
            ss << count;
            ss >> scount;
            ret += scount + string(1, cur_c);
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(5);
}
