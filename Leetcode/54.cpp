#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int cu0=0, cu1=matrix.size()-1; ///上行
        int cd0=matrix.size()-1, cd1=0; ///下行
        int rl0=matrix.size()-2, rl1=1; ///左列
        int rr0=1, cd1=matrix.size()-2; ///右列
        for(int i=cu0; i<=cu1; i++)
            res.push_back(matrix[][]);

    }
};

int main() {
    return 0;
}


