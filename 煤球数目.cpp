#include<iostream>
using namespace std;
int main(){
	int cur = 0;
	int sum = 0;
	int pre = 0;
	for(int i=1; i<=100; i++){
		pre = pre + i;
		sum += pre;
	}
	cout << sum << endl;
	return 0;
}
