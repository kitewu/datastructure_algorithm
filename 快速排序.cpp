#include<iostream>
using namespace std;

void quickSort(int *arr, int left, int right){
	if(left<right){
		int begin=arr[left];
		int a=left, b=right;
		while(a<b){
			while(a<b && arr[b]>=begin)b--;
			while(a<b && arr[a]<=begin)a++;
			if(a<b){
				arr[a]=arr[a]^arr[b];
				arr[b]=arr[a]^arr[b];
				arr[a]=arr[a]^arr[b];
			}
		}
		arr[left]=arr[a];
		arr[a]=begin;
		quickSort(arr, left, a-1);
		quickSort(arr, a+1, right);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	quickSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}
