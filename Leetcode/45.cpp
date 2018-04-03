#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;//当前跳数
        int last = 0;//上一跳可达最远距离
        int cur = 0;//当前一跳可达最远距
        for (int i = 0; i < nums.size(); ++i) {
            //需要进行下次跳跃，则更新last和当执行的跳数ret
            if (i > last) {
                last = cur;
                ++ret;
            }
            //记录当前可达的最远点
            cur = max(cur, i+nums[i]);
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> vv;
    vv.push_back(2);
    vv.push_back(3);
    vv.push_back(1);
    vv.push_back(1);
    vv.push_back(4);
    cout << s.jump(vv);
}

