#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        if(size <= 0)
            return 0;
        minn = 0x7FFFFFFF;
        dfs(s, size, size-1, 0);
        return minn-1;
    }

    void dfs(string str, int size, int start, int cur_time) {
        if(start == size) {
            if(cur_time < minn)
                minn = cur_time;
            return;
        }
        for(int i = start; i < size; ++i) {
            string t = str.substr(start, i-start+1);
            if(IsPalindrome(t)) {
                dfs(str, size, i+1, cur_time+1);
            }
        }
    }

    /// ÅÐ¶Ï×Ö·û´®ÊÇ·ñÊÇ»ØÎÄ´®
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
    int minn;
};

int main() {
}

