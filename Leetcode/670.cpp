#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    ///整型数组转int
    int toInt(int* arr, int n){
        int res = 0;
        for(int i=0; i<n; i++){
            res = res*10 + arr[i];
        }
        return res;
    }

    int maximumSwap(int num) {
        ///首先获得每一位数字的数组
        int arr[20] = {0};
        int back = num, n = 0;
        while(back){
            arr[n++] = back % 10;
            back /= 10;
        }
        for(int i=0, j=n-1; i<j; i++, j--)
            swap(arr[i], arr[j]);
        ///从高位向低位扫描
        for(int i=0; i<n; i++){
            int maxn = arr[i];
            int index = i;
            for(int j=i+1; j<n; j++){
                if(arr[j] >= maxn){
                    index = j;
                    maxn = arr[j];
                }
            }
            if(maxn > arr[i]){
                swap(arr[i], arr[index]);
                return toInt(arr, n);
            }
        }
        return num;
    }
};

int main(){
    Solution s;
    cout << s.maximumSwap(123);
    return 0;
}
