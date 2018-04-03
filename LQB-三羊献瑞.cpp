#include<iostream>
#include<cstring>
using namespace std;

bool check(int a, int b, int sum){
	int arr[10] = {0};
	memset(arr, 0, 10 * sizeof(int));
	while(){
		
	}
}

int main(){	
	for(int i=1234; i<=9876; i++){
		for(int j=1234; j<=9876; j++){
			if(check(i, j, i+j)){
				cout << i << " " << j << endl;
				goto end;
			}
		}
	}
	end:
		return 0;
}
