#include<iostream>
#include<cstring>
using namespace std;

int count=0;

void judge(int arr[], int a, int b, int c){
	for(int i=123; i<=987; i++){
		int flag = true;
		int x=i;
		while(x){
			int index = x % 10;
			if(index == 0 || arr[index] > 0){
				flag = false;
				break;
			}
			else{
				arr[x%10]++;
				x/=10;
			}
		}
		if(flag){
			for(int j=123; j<=987; j++){
				int y=j;
				bool flag1 = true;
				while(y){
					int index = y % 10;
					if(index == 0 ||  arr[index] > 0){
						flag1 = false;
						break;
					}
					else{
						arr[y%10]++;
						y/=10;
					}
				}
				if(flag1){
					double v = 1.0 * (b * j + c * i) / (j * c);
					if(10-a == v){
						count++;
						cout << a << " " << b << " " << c << " " << i << " " << j << endl;
					}
				}
			}
		}
	}
}

int main(){
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			if(i == j)
				continue;
			for(int k=1; k<=9; k++){
				if(j == k || i == k)
					continue;
				int arr[10];
				memset(arr, 0, sizeof(int) * 10); 
				arr[i]++;
				arr[j]++;
				arr[k]++;
				judge(arr, i, j, k);
			}
		}
	}	
	cout << count << endl;
}
