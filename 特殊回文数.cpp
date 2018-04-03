#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 10; i <= 99; i++) {
        stringstream ss;
        ss << i;
        string str;
        ss >> str;
        for(int j = 0; j <= 9; j++) {
            if((str[0] + str[1] - 48 * 2) * 2 + j == n) {
                stringstream ss_mid;
                ss_mid << j;
                string mid;
                ss_mid >> mid;

                stringstream sss(str + mid + str[1] + str[0]);
                int result;
                sss >> result;
                cout << result << endl;
            }
        }
    }

    for(int i = 100; i <= 999; i++) {
        stringstream ss;
        ss << i;
        string str;
        ss >> str;
        if((str[0] + str[1] + str[2] - 48 * 3) * 2 == n) {
            stringstream sss(str + str[2] + str[1] + str[0]);
            int result;
            sss >> result;
            cout << result << endl;
        }
    }
}
