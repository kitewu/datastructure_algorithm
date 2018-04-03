#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> f1(n);  // 表示在[0,i]内进行买入卖出所能获得的最大profit
        vector<int> f2(n);  // 表示在[i, n-1]内进行买入卖出所能获得的最大profit  结果就为max(f1[i]+f2[i])

        int minPrice = prices[0];

        for(int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            f1[i] = max(f1[i-1], prices[i]- minPrice);
        }

        int maxPrice = prices[n-1];
        for(int i = n-2; i >=0; i--) {    // 这里要从后往前遍历
            maxPrice = max(maxPrice, prices[i]);
            f2[i] = max(f2[i+1], maxPrice - prices[i]);
        }
        int maxResult = 0;
        for(int i = 0; i < n; i++)
            maxResult = max(maxResult, f1[i]+f2[i]);
        return maxResult;
    }
};

int main() {
    return 0;
}


