#include<iostream>
#include<string>
#include<cctype>
#include<list>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> jc; ///½×³Ë±í
        list<int> li;   ///ÐòÁÐ 1234
        jc.push_back(1);
        int i=1;
        for(; i<n; i++) {
            jc.push_back(jc[i-1]*i);
            li.push_back(i);
        }
        li.push_back(i);

        --k;
        string res="";
        list<int>::iterator it;
        for(int i=n-1; i>0; i--) {
            int index = k/jc[i];
            it = li.begin();
            for(int j=0; j<index; j++) it++;
            res += to_string(*it);
            li.erase(it);
            k = k % jc[i];
        }
        res += to_string(*li.begin());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(4, 6);
    return 0;
}
