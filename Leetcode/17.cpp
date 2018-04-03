#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string table[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        letterCombinations1(result, digits, "", 0, table);
        return result;
    }

    void letterCombinations1(vector<string> &result, string &digits, string curr, int index, string table[]) {
        if(index == digits.size()) {
            if(curr.size() != 0)
                result.push_back(curr);
            return;
        }
        string temp = table[digits[index] - '0'];
        for(int i = 0; i < temp.size(); i++) {
            letterCombinations1(result, digits, curr + temp[i], index + 1, table);
        }
    }
};

int main() {
    Solution s;
    vector<string> v;
    v = s.letterCombinations("234");
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

