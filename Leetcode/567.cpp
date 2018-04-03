#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2)
            return false;
        vector<int> vv1(26);
        vector<int> vv2(26);
        for(int i=0; i<len1; i++) {
            vv1[s1[i]-'a']++;
            vv2[s2[i]-'a']++;
        }
        if(vv1 == vv2)
            return true;
        for(int i=0; i<len2-len1; i++){
            vv2[s2[i]-'a']--;
            vv2[s2[i+len1]-'a']++;
            if(vv1 == vv2)
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
