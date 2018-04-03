#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int begin = 0;
        res.push_back(0);
        for(int i=0; i<n; i++){
            for(int j=res.size()-1; j>=0; j--){
                int cur = res[j];
                cur += (1 << i);
                res.push_back(cur);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

