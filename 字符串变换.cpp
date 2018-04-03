#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    if(1 == n) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        cout << str;
    } else if(2 == n) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        cout << str;
    } else if(3 == n) {
        for(int i = str.size() - 1; i >= 0; i--)
            cout << str[i];
        cout << endl;
    } else if(4 == n) {
        for(int i = 0; i < str.size(); i++) {
            if(str[i] >= 'a' && str[i] <= 'z')
                cout << (char)(str[i] - 32);
            else
                cout << (char)(str[i] + 32);
        }
    } else if(5 == n) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        char result[210];
        int pos = 1;
        result[0] = str[0];
        for(int i = 1; i < str.size();) {
            if(str[i] - str[i - 1] == 1) {
                int flag = 0;
                while(str[i] - str[i - 1] == 1 && i < str.size()) {
                    i++;
                    flag++;
                }
                if(flag >= 2) {
                    result[pos++] = '-';
                    result[pos++] = str[i - 1];
                } else {
                    result[pos++] = str[i - 1];
                    result[pos++] = str[i];
                }
            } else {
                result[pos++] = str[i++];
            }
        }
        result[pos] = 0;
        printf("%s", result);
    }
    return 0;
}
