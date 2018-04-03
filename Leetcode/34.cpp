#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> result(2, -1);
    	if(nums.size() == 0)
    		return result;
    	int ll = 0, lr = nums.size() - 1, mid;
    	while(ll <= lr){
    		mid = (ll + lr) / 2;
    		if(nums[mid] < target)
    			ll = mid + 1;
    		else
    			lr = mid - 1;
		}
		int rl = 0, rr = nums.size() - 1;
		while(rl <= rr){
    		mid = (rl + rr) / 2;
    		if(nums[mid] <= target)
    			rl = mid + 1;
    		else
    			rr = mid - 1;
		}
		if(ll <= rr){
			result[0] = ll;
			result[1] = rr;
		}
        return result;
    }
};

int main(){
}
