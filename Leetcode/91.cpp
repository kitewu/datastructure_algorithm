#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int numDecodings(const string &s) {
        if (s.empty() || s[0] == '0') return 0;

        int prev = 0;
        int cur = 1;

        for (size_t i = 1; i <= s.size(); ++i) {
            if (s[i-1] == '0') cur = 0;

            if (i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                prev = 0;

            int tmp = cur;
            cur = prev + cur;
            prev = tmp;
        }
        return cur;
    }
    int numDecodings(const string &s) {
        if (s.empty() || s.size() == 0) return 0;
        int nums[s.size()+1];
        memset(nums, 0, sizeof(int)*(s.size()+1));
        nums[0] = 1;
        for(int i=1; i<=s.size(); i++) {
            if (s[i-1] != '0') nums[i] += nums[i-1];
            if (i>1 && s[i-2] == '1') nums[i] += nums[i-2];
            if (i>1 && s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6') nums[i] += nums[i-2];
        }
        return nums[s.size()];
    }
};
int main() {
    return 0;
}
