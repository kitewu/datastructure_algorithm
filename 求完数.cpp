#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int sum = 0;
	for(int i = 2; i <= 9999; i++){
		sum = 0;
		for(int j = 1; j <= i / 2; j++){
			if(i % j == 0)
				sum += j;
		}
		if(sum == i)
			cout << i << endl;
	}
	return 0;
}
