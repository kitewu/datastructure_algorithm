#include<iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        int* flag = new int[n]();
        for(int i=2; i<n; i++){
            if(flag[i] == 0){
                count++;
                for(int j=2; j*i<n; j++)
                    flag[j*i] = 1;
            }
        }
        return count;
    }
};

int main() {
    return 0;
}
