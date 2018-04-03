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
        
        int cur=0, n=nums.size();
        vector<int> v;
        v.push_back(nums[0]);
		for(int i=1; i<n; i++)
			if(v[cur] != nums[i])
				v[++cur]=nums[i];
		++cur;
        
        int temp_sum, i, j;
		for(int k=0; k<cur-1; k++){
			i=k+1, j=n-1;
			while(i < j){
				temp_sum = nums[i] + nums[j] + v[k];
				if(temp_sum == 0){//相等，i，j为一组解，输出下标 
					vector<int> temp;
					temp.push_back(v[k]);
					temp.push_back(nums[i++]);
					temp.push_back(nums[j--]);
					result.push_back(temp);
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
