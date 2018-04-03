#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(k > nums.size())
            return 0;
        double sum = 0;
        for(int i=0; i<k; i++)
            sum += nums[i];
        double max = sum;
        for(int i=k, j=0; i<nums.size(); i++, j++){
            sum = sum - nums[j] + nums[i];
            if(max < sum)
                max = sum;
        }
        return max / k;
    }
};

int main() {
    return 0;
}
