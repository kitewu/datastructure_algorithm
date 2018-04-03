#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0 && b.size() == 0)
            return "";
        if(a.size() == 0)
            return b;
        if(b.size() == 0)
            return a;

        int len = max(a.size(), b.size());
        char arr[len+2];
        arr[0] = '1';
        arr[len+1] = 0;
        int cur = len;

        int i = a.size()-1, j = b.size()-1;
        int jw = 0;

        while(i != 0 && j != 0) {
            int r = a[i--]-'0'+ b[j--]-'0'+jw;
            jw = r/2;
            arr[cur--] = (char)(r%2+'0');
        }
        while(i != 0) {
            int r = a[i--]-'0'+jw;
            jw = r/2;
            arr[cur--] = (char)(r%2+'0');
        }
        while(j != 0) {
            int r = b[j--]-'0'+jw;
            jw = r/2;
            arr[cur--] = (char)(r%2+'0');
        }
        if(jw==1)
            return string(arr);
        else
            return string(arr+1);
    }
};

int main() {
    Solution s;
    cout << s.addBinary("11", "1");
}
