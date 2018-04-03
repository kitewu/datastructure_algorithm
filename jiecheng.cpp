#include<iostream>
using namespace std;
int main(){
    long long sum = 1;
    for(int i=1; i<=17; i++)
        sum *= i;
    cout << sum << endl;
    return 0;
}
