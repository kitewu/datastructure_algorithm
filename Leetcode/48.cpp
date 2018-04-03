#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        //沿副对角线翻转
        for(int i=0; i<n; i++)
            for(int j=0; j<n-1-i; j++)
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        //沿横横中轴线翻转
        for(int i=0; i<n; i++)
            for(int j=0; j<n/2; j++)
                swap(matrix[j][i], matrix[n-j-1][i]);
    }
};

int main() {
    vector<vector<int> > vv;
    const int n = 6;
    for(int i=0; i<n; i++) {
        vector<int> v;
        for(int j=1; j<=n; j++)
            v.push_back(i*n+j);
        vv.push_back(v);
    }
    Solution s;
    s.rotate(vv);
}
