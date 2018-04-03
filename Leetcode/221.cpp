#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int arr[m][n];
        int maxlen = 0;
        memset(arr, 0, m*n*sizeof(int));
        for(int i=0; i<m; i++){
            arr[0][i] = matrix[0][i]-'0';
            if(arr[0][i] == 1)
                maxlen = 1;
        }
        for(int i=0; i<n; i++){
            arr[i][0] = matrix[i][0]-'0';
            if(arr[i][0] == 1)
                maxlen = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == '0')
                    arr[i][j] = 0;
                else{
                    arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1])) + 1;
                    maxlen = max(arr[i][j], maxlen);
                }
            }
        }
    }
};

int main() {
    return 0;
}
