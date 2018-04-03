#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        string add(string s1, string s2) {
            string result;
            int flag = 0, i = s1.size()-1, j = s2.size()-1;
            while(i >=0 || j >=0) {
                int num1=0, num2=0;
                if(i >=0)
                    num1 = s1[i]-'0';
                if(j >= 0)
                    num2 = s2[j]-'0';
                result.insert(result.begin(), '0'+(num1+num2+flag)%10);
                flag = (num1+num2+flag)/10;
                i--, j--;
            }
            if(flag == 1)
                result.insert(result.begin(), '1');
            return result;
        }

        bool DFS(string num, string num1, string num2) {
            if(num.size()==0 || num[0] == '0')
                return false;
            for(int i =0; i < num.size(); i++) {
                string x = num.substr(0, i+1);
                if(x ==add(num1,num2)) {
                    if(i == num.size()-1)
                        return true;
                    return DFS(num.substr(i+1), num2, x);
                }
            }
            return false;
        }

        bool isAdditiveNumber(string num) {
            int len = num.size();
            if(len < 3) return false;
            string num1, num2;
            for(int i = 0; i < len-2; i++) {
                num1 = num.substr(0, i+1);
                for(int j = i+1; j < len-1; j++) {
                    num2 = num.substr(i+1, j-i);
                    if(DFS(num.substr(j+1), num1, num2))
                        return true;
                    if(num[i+1] == '0')
                        break;
                }
                if(num[0] == '0')
                    break;
            }
            return false;
        }
    }
};

int main() {
}
