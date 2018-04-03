#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 101;
int main(){
	int n, value, t;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int sum = 1;
	if(arr[0] > 0){
		for(int i = 1; i < n; i++)
			if(arr[i] < 0 && abs(arr[i]) > arr[0])
				sum++;
		for(int i = 1; i < n; i++)
			if(arr[i] > 0 && abs(arr[i]) < arr[0])
				sum++;
	}else{
		arr[0] = -arr[0];
		for(int i = 1; i < n; i++)
			if(arr[i] > 0 && abs(arr[i]) < arr[0])
				sum++;
		for(int i = 1; i < n; i++)
			if(arr[i] < 0 && abs(arr[i]) > arr[0])
				sum++;
	}
	cout << sum << endl;
	return 0;
}
