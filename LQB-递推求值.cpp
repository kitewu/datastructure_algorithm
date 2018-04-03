#include<iostream>
using namespace std;

int func(int n, int m) {
    if(n == 1 && m == 1)
        return 2;
    else if(n == 1 && m == 2)
        return 3;
    else if(n == 2 && m == 1)
        return 1;
    else if(n == 2 && m == 2)
        return 4;
    else if(n == 3 && m == 1)
        return 6;
    else if(n == 3 && m == 2)
        return 5;
    else {
        int result;
        if(m == 1)
            result = func(n-1, 2) + 2 * func(n-3, 1) + 5;
        else
            result = func(n-1, 1) + 3 * func(n-3, 1) + 2 * func(n-3, 2) + 3;
        result %= 99999999;
        return result;
    }
}

int main() {
    int n;
    cin >> n;
    cout << func(n, 1) << endl;
    cout << func(n, 2) << endl;
//    for(int i=1; i<30; i++) {
//        cout << i << " " << func(i, 1) << " ";
//        cout << func(i, 2) << endl;
//    }
    return 0;
}
