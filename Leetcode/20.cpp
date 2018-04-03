#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stac;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stac.push(s[i]);
            else {
                if(stac.empty())
                    return false;
                if(s[i] == ')') {
                    if(stac.top() != '(')
                        return false;
                }
                else if(s[i] == ']') {
                    if(stac.top() != '[')
                        return false;
                }
                else if(s[i] == '}') {
                    if(stac.top() != '{')
                        return false;
                }
                stac.pop();
            }
        }
        return stac.empty() ? true : false;
    }
};

int main() {

}
