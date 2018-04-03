#include<algorithm>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4)
        	return result;
		sort(nums.begin(), nums.end());
		set<vector<int> > se;
		int len = nums.size();
		for(int i=0; i<len-3; i++){
			for(int j=i+1; j<len-2; j++){
				int begin=j+1;
				int end=len-1;
				while(begin<end){
					int sum=nums[i]+nums[j]+nums[begin]+nums[end];
					if(sum == target){
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[begin++]);
						temp.push_back(nums[end--]);
						se.insert(temp);
					}else if(sum < target)
						begin++;
					else
						end--;
				}
			}	
		}
		set<vector<int> >::iterator it;
		for(it=se.begin(); it!=se.end();it++)
			result.push_back(*it);
		return result;
    }
};

int main(){
	
}
