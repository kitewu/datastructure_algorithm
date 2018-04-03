#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int t = n;
    int count=0;
    while(n >= 3){
        n-=2;
        count++;
    }
    cout << t+count << endl;
    return 0;
}

