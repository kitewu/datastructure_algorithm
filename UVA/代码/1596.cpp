#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<sstream>
#include<cctype>
#include<map>
using namespace std;

class Array {//一个数组，包含长度和已经赋值的下标
public:
    Array(int l = 0) : len(l) {}
    int len;//长度
    map<int, int> value;//赋值的下标
};

map<string, Array> mmap;//存储声明的数组
bool flag = true;

//获得数组的名字
string getName(string str) {
    return str.substr(0, str.find_first_of('['));
}

//获取[]中的内容
string getValue(string str) {
    int pos1 = str.find_first_of('[');
    int pos2 = str.find_last_of(']');
    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

//递归获得值
int getNum(string str) {
    if(isdigit(str[0])) {
        int pos = 0;
        stringstream ss(str);
        ss >> pos;
        return pos;
    } else {
        string name = getName(str);
        int pos = getNum(getValue(str));
        if(!mmap[name].value.count(pos)){
            flag = false;
            return 0;
        }
        return mmap[name].value[pos];
    }
}

//添加节点
bool addArray(string str) {
    string name = getName(str);
    flag = true;
    int len = getNum(getValue(str));
    if(!flag)
        return false;
    mmap[name] = Array(len);
    return true;
}

//处理赋值等号前半部分
bool dealFront(string str_front, int &pos_f){
    string name = getName(str_front);
    flag = true;
    pos_f = getNum(getValue(str_front));
    if(!flag)
        return false;
    if(mmap[name].len <= pos_f)
        return false;
    return true;
}

//处理赋值等号后半部分
bool dealBack(string str_back, int &value_b){
    flag = true;
    value_b = getNum(str_back);
    if(!flag)
        return false;
    return true;
}

//赋值
bool massign(string row) {
    int equelpos = row.find_first_of('=');
    string str_front = row.substr(0, equelpos);
    string str_back = row.substr(equelpos + 1);
    int pos_f = 0;
    int value_b = 0;
    if(!dealFront(str_front, pos_f)) return false;
    if(!dealBack(str_back, value_b)) return false;
    string name = getName(str_front);
    mmap[name].value[pos_f] = value_b;
    return true;
}

int main() {
    string str;
    while(cin >> str) {
        if(str[0] == '.')
            break;
        mmap.clear();
        vector<string> vv;
        vv.push_back(str);
        string ss;
        while(cin >> ss) {
            if(ss[0] == '.')
                break;
            vv.push_back(ss);
        }
        int pos = 0;
        for(int i = 0; i < vv.size(); i++) {
            string row = vv[i];
            if(row.find_first_of('=') == row.npos) { //声明数组
                if(!addArray(row)) {
                    pos = i + 1;
                    break;
                }
            } else { //赋值
                if(!massign(row)) {
                    pos = i + 1;
                    break;
                }
            }
        }
        cout << pos << endl;
    }
    return 0;
}
