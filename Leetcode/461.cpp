#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dic = 0;
        for(int i=0; i<32; i++){
            if((x&1) ^ (y&1))
                dic++;
            x >>= 1;
            y >>= 1;
        }
        return dic;
    }
};

int main()
{
    Solution s;
    cout << s.hammingDistance(1, 4);
    return 0;
}
