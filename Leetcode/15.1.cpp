#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	vector<vector<int> > result;
    	if(nums.size() == 0)
    		return result;
        sort(nums.begin(), nums.end());
        
        int temp_sum, i, j, n=nums.size();;
		for(int k=0; k<n; k++){
			while(k>0 && k<n && nums[k] == nums[k-1])
				k++;
			i=k+1, j=n-1;
			while(i < j){
				temp_sum = nums[i] + nums[j] + nums[k];
				if(temp_sum == 0){//相等，i，j为一组解，输出下标 
					vector<int> temp;
					temp.push_back(nums[k]);
					temp.push_back(nums[i++]);
					temp.push_back(nums[j--]);
					result.push_back(temp);
					while(i<j && nums[i] == nums[i-1])
						i++;
					while(i<j && nums[j] == nums[j+1])
						j--;
				}else if(temp_sum > 0)//大于target，j左移 
					j--;
				else//小于target，i右移 
					i++;
			}
		}
		return result;
    }
};

int main(){
	vector<int> v;
	int n;
	for(int i = 0; i < 6; i++){
		cin >> n;
		v.push_back(n);
	}
	Solution s;
	s.threeSum(v);
}
