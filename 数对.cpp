#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n, count = 0;
    cin >> n;
    int mid = (int)sqrt(n);
    int a[mid], b[mid];
    for(int i = 1; i <= mid; i++){
        double re = n  * 1.0 / i;
        if(re == (int)re){
            cout << i << " * " << re << " = " << n << endl;
            if(i != re){
                a[count] = re;
                b[count++] = i;
            }
        }
    }
    for(int i = count - 1; i >= 0; i--){
        cout << a[i] << " * " << b[i] << " = " << n << endl;
    }
    return 0;
}
