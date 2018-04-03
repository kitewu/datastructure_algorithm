#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (modified) return false;
                (i - 2 < 0 || nums[i - 2] <= nums[i]) ? nums[i - 1] = nums[i] : nums[i] = nums[i - 1];
                modified = true;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
