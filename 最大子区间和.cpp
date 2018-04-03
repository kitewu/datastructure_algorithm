#include<iostream>
#include<algorithm>
using namespace std;

int MaxSubSum(int arr[], int len){
    int maxlocal = arr[0];
    int res = arr[0];
    for(int i=1; i<len; i++){
        maxlocal = max(arr[i], arr[i]+maxlocal);
        res = max(res, maxlocal);
    }
    return res;
}

int  MaxSubSum(int arr[], int x, int y){
    if(y - x == 1)///只有一个元素，直接返回
        return arr[x];
    int mid = x+(y-x)/2;
    int maxs = max(MaxSubSum(arr, x, mid), MaxSubSum(arr, mid, y));///递归选择左右区间的最大值
    int v = 0, L = arr[mid-1], R = arr[mid];
    for(int i=mid-1; i>=x; i--)///合并1，从中间往左找最大连续和
        L = max(L, v+=arr[i]);
    v = 0;
    for(int i=mid; i<y; i++)///合并2，从中间往右找最大连续和
        R = max(R, v+=arr[i]);
    return max(maxs, L+R);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << MaxSubSum(arr, n) << endl;
    cout << MaxSubSum(arr, 0, n);
}
