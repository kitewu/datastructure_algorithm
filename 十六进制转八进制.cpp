#include<iostream>
#include<string>
#include<map>
#include<cctype>

using namespace std;

map<char, string> m16;
map<string, string> m8;

void init();

string toBinary(string hex) {
    string bin = "";
    for(int i = 0; i < hex.size(); i++)
        bin += m16[hex[i]];
    return bin;
}

string toOctal(string bin) {
    for(int i = 0; i < bin.size() % 3; i++)
        bin = '0' + bin;
    string oct = "";
    for(int i = 0; i < bin.size(); i += 3){
        string key = bin.substr(i, 3);
        oct += m8[key];
    }
    if(oct[0] == '0')
        return oct.substr(1);
    return oct;
}

int main() {
    init();
    int n;
    cin >> n;
    string hex;
    while(n--) {
        cin >> hex;
        cout << toOctal(toBinary(hex)) << endl;
    }
    return 0;
}

void init() {
    m16['0'] = "0000";
    m16['1'] = "0001";
    m16['2'] = "0010";
    m16['3'] = "0011";
    m16['4'] = "0100";
    m16['5'] = "0101";
    m16['6'] = "0110";
    m16['7'] = "0111";
    m16['8'] = "1000";
    m16['9'] = "1001";
    m16['A'] = "1010";
    m16['B'] = "1011";
    m16['C'] = "1100";
    m16['D'] = "1101";
    m16['E'] = "1110";
    m16['F'] = "1111";

    m8["000"] = "0";
    m8["001"] = "1";
    m8["010"] = "2";
    m8["011"] = "3";
    m8["100"] = "4";
    m8["101"] = "5";
    m8["110"] = "6";
    m8["111"] = "7";
}
