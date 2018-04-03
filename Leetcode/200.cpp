#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int value = '2';
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    setValue(grid, i, j, value++);
                }
            }
        }
        return (int)(value-'2');
    }
    void setValue(vector<vector<char> >& grid, int row, int col, int value){
        if(row < 0 || row >= grid.size() ||
           col < 0 || col >= grid[0].size())
            return;
        if(grid[row][col] == '1'){
            grid[row][col] = value;
            setValue(grid, row-1, col, value);
            setValue(grid, row+1, col, value);
            setValue(grid, row, col+1, value);
            setValue(grid, row, col-1, value);
        }
    }
};

int main() {
    vector<vector<char> > vv;
    vector<char> v0;
    v0.push_back('1');
    v0.push_back('1');
    v0.push_back('1');
    vector<char> v1;
    v1.push_back('0');
    v1.push_back('1');
    v1.push_back('0');
    vector<char> v2;
    v2.push_back('1');
    v2.push_back('1');
    v2.push_back('1');
    vv.push_back(v0);
    vv.push_back(v1);
    vv.push_back(v2);
    Solution s;
    cout << s.numIslands(vv);
    return 0;
}

