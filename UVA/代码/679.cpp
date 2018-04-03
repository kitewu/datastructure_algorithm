#include<iostream>
using namespace std;
int main() {
    int D, I;
    int n;
    while(cin >> n && n != -1) {
        while(n--) {
            cin >> D >> I;
            int k = 1;
            for(int i = 0; i < D - 1; i++) {
                if(I % 2) {
                    k *= 2;
                    I = (I + 1) / 2;
                } else {
                    k = k * 2 + 1;
                    I /= 2;
                }
            }
            cout << k << endl;
        }
    }
    return 0;
}



//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//const int maxn = 20;
//bool a[1 << maxn];
//int main()
//{
//    int d, n;
//    while(scanf("%d%d", &d, &n) == 2){
//        memset(a, 0, sizeof(a));
//        int pos = 1;
//        for(int i = 0; i < n; i++){
//            pos = 1;
//            for(int i = 1; i < d; i++){
//                bool stat = a[pos];
//                a[pos] = !a[pos];
//                pos = stat ? pos * 2 + 1 : pos * 2;
//            }
//        }
//        cout << pos << endl;
//    }
//    return 0;
//}
