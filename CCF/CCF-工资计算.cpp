#include<cstdio>
#include<iostream>
using namespace std;
int main() {
    int v = 0;
    int T;
    int end = 20 * T;
    scanf("%d", &T);
    if(T <= 3500)
        v = T;
    else {
        for(int S = T; S < end; S++) {
            int A = S - 3500;
            double sum = 0;
            if(A <= 1500) {
                sum = A * 0.03;
            } else if(A > 1500 && A <= 4500) {
                sum = (A - 1500) * 0.1 + 1500 * 0.03;  //45
            } else if(A > 4500 && A <= 9000) {
                sum = (A - 4500) * 0.2 + 3000 * 0.1 + 1500 * 0.03; // 345
            } else if(A > 9000 && A<= 35000) {
                sum = (A - 9000) * 0.25 + 4500 * 0.2 + 3000 * 0.1 + 1500 * 0.03; //1245
            } else if(A > 35000 && A <= 55000) {
                sum = (A - 35000) * 0.3 + 26000 * 0.25 + 4500 * 0.2 + 3000 * 0.1 + 1500 * 0.03;//7745
            } else if(A > 55000 && A<= 80000) {
                sum = (A - 55000) * 0.35 + 20000 * 0.3 + 26000 * 0.25 + 4500 * 0.2 + 3000 * 0.1 + 1500 * 0.03;//13745
            } else if(A > 80000) {
                sum = (A - 80000) * 0.45 + 25000 * 0.35 + 20000 * 0.3 + 26000 * 0.25 + 4500 * 0.2 + 3000 * 0.1 + 1500 * 0.03;//25995
            }
          //  cout << sum << endl;
            if((int)sum == sum) {
                if(S - (int)sum == T) {
                    v = S;
                    break;
                }
            }
        }
    }
    printf("%d\n", v);
    return 0;
}
