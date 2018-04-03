#include<iostream>
using namespace std;
int main(){
    for(int i=1; i<=48; i++){
        for(int j=i+1; j<=48; j++){
            if(i*i+j*j-i-j==2015-1225+2)
                cout << i << " " << j << endl;
        }
    }
}
