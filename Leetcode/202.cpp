#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        set<int> sset;
        while((n!=1) && (sset.find(n) == sset.end())) {
            sset.insert(n);
            int sum = 0;
            while(n) {
                int y = n%10;
                sum += y*y;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19);
    return 0;
}
