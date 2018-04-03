#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
            return;
        stringstream ss(s);
        string temp;
        vector<string> v;
        while(ss >> temp) {
            v.push_back(temp);
        }
        if(v.size() == 0){
            s = "";
            return ;
        }

        for(int i=0, j=v.size()-1; i <= j; i++, j--){
            string aa = v[i];
            v[i] = v[j];
            v[j] = aa;
        }
        s.clear();
        s += v[0];
        for(int i=1; i<v.size(); i++) {
            s += " " + v[i];
        }
        cout << s;
    }
};

int main() {
    Solution s;
    string str(" ");
    s.reverseWords(str);
    return 0;
}
