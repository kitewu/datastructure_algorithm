#include<iostream>
#include<vector>
using namespace std;

//¶þ·Ö·¨
int binarySearch(vector<int> &vv, int low, int high, int target){
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(vv[mid] > target)
        return binarySearch(vv, low, mid - 1, target);
    if(vv[mid] < target)
        return binarySearch(vv, mid + 1, high, target);
    return mid;
}

int main(){
    int n;
    cin >> n;

    vector<int> vv;
    for(int i = 0; i < n; i++){
        cin >> vv[i];
    }

    int target;
    cin >> target;

    cout << binarySearch(vv, 0, n - 1, n);
}
