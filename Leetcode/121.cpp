#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int curr = prices[0];
        int profit = 0;
        for(int i=0; i<prices.size(); i++){
            int nex = prices[i]-curr;
            profit = nex > profit ? nex : profit;
            curr = curr < prices[i] ? curr : prices[i];
        }
        return profit;
    }
};

int main() {
    return 0;
}

