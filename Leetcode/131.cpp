#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        int size = s.size();
        if(size <= 0)
            return result;
        dfs(s, size, 0);
        return result;
    }

    void dfs(string str, int size, int start) {
        if(start == size) {
            result.push_back(path);
            return;
        }
        for(int i = start; i < size; ++i) {
            string t = str.substr(start, i-start+1);
            if(IsPalindrome(t)) {
                path.push_back(t);
                dfs(str, size, i+1);
                path.pop_back();
            }
        }
    }

    /// 判断字符串是否是回文串
    bool IsPalindrome(string str) {
        int size = str.size();
        if(size == 0)
            return false;
        for(int i=0, j=size-1; i<j; i++, j--)
            if(str[i] != str[j])
                return false;
        return true;
    }
private:
    vector<string> path;///中间结果
    vector<vector<string> > result; ///最终结果
};

int main() {
}
