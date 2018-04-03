#include<iostream>
using namespace std;

bool check(int n){
	while(n){
		if(n%10==4)
			return false;
		n /= 10;
	}
	return true;
}

int main(){
	int count=0;
	for(int i=10000; i<=99999; i++)
		if(check(i))
			count++;
	cout << count << endl;
	return 0;
}
