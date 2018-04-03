#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res[2];
        int flag = 0;
        res[flag].push_back(1);
        if(rowIndex <= 0)
            return res[flag];
        int next;
        for(int i=0; i<rowIndex; i++) {
            next = (flag+1)%2;
            res[next].clear();
            res[next].push_back(1);
            for(int i=0; i<res[flag].size()-1; i++)
                res[next].push_back(res[flag][i]+res[flag][i+1]);
            res[next].push_back(1);
            flag = next;
        }
        return res[flag];
    }
};

int main() {
    Solution s;
    s.getRow(3);
    return 0;
}

