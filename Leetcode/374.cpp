#include <iostream>
using namespace std;

int guess(int num) {
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int res;
        int mid;
        while(high > low) {
            mid = low + (high - low) / 2;
            res = guess(mid);
            if(res == 1) low = mid + 1;
            else if(res == -1) high = mid - 1;
            else return mid;
        }
        return low;
    }
};

int main() {
    return 0;
}
