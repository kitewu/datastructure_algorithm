#include<iostream>
#include<string>
using namespace std;
int main() {
    string input;
    while(cin >> input) {
        unsigned long long res = 0;
        for(int i=0; i<input.size(); i++) {
            res = res * 26 + input[i] - 'a';
        }
        cout << res << endl;
    }
    return 0;
}
