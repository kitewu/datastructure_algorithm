#include<iostream>
using namespace std;
int main(){
    for(int i = 100; i <= 999; i++){
        int j = i;
        int sum = 0;
        while(j){
            int t = j % 10;
            sum += t * t * t;
        }
        if(sum == i)
            cout << i << endl;
    }
    return 0;
}
