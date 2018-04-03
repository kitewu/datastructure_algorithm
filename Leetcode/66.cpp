#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--) {
            if(digits[i] != 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(0);
//    v.push_back(9);
//    v.push_back(9);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(4);
//    v.push_back(5);
    s.plusOne(v);
}
