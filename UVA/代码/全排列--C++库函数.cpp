#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin >> n){
        int P[n];
        for(int i = 0; i < n; i++)
            cin >> P[i];
        sort(P, P + n);
        while(next_permutation(P, P + n)){
            for(int i = 0; i < n; i++)
                cout << P[i] << " ";
            cout << endl;
        }
    }
}
