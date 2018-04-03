#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int a = 11, b = 17, c = 0, m = 11, n = 17;
	while(b){
		c = a % b;
		a = b;
		b = c;
	}
	for(int i = 1; i < 10; i++){
		int v = m * n / a * i;
		if(v > 1000)
			break;
		cout << v << endl;
	}
}
