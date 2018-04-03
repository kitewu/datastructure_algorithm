#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == s2)
        cout << 2;
    else if(s1.size() != s2.size())
        cout << 1;
    else {
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if(s1 == s2)
            cout << 3;
        else
            cout << 4;
    }
    return 0;
}
