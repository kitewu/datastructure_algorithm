#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right){
	if(right - left < 0)
		return -1;
	else if(right - left == 0)
		return left;
	else if(right - left == 1)
		return arr[right] > arr[left] ? left : right;
	int mid = (right+left)/2;
	if(arr[mid] < arr[left] && arr[mid] < arr[right]){
		
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
}
