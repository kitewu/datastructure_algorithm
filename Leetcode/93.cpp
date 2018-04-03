#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(string &s, vector<string>& ret, int startidx, string mstr, int depth) {
        if(depth > 4)
            return;
        if(depth==4 && startidx==s.length())
            ret.push_back(mstr);
        else {
            for(int i=1; i<4; i++) {
                if(startidx+i > s.length())
                    continue;
                string subs = s.substr(startidx, i);
                if(subs[0]=='0' && i>1 || stoi(subs)>=256 && i==3)
                    continue;
                dfs(s, ret, startidx+i, mstr+subs+(depth==3?"":"."), depth+1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        dfs(s, ret, 0, "", 0);
        return ret;
    }
};

int main() {
    Solution s;
    //string str("25525511135");
    string str("010010");
    vector<string> vec = s.restoreIpAddresses(str);
    for(int i = 0; i < vec.size(); ++i) {
        cout<<vec[i]<<endl;
    }//for
    return 0;
}
