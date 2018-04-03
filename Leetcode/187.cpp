#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> r;
        for (int t = 0, i = 0; i < s.size(); i++)
            if (m[t = (t<<3) | (s[i]&7) & 0x3FFFFFFF]++ == 1)
                r.push_back(s.substr(i - 9, 10));
        return r;
    }

//    vector<string> findRepeatedDnaSequences(string s) {
//        vector<string> res;
//        if(s.empty() || s.length() < 11)
//            return res;
//
//        map<char, int> ff;
//        ff.insert(make_pair('A', 0));
//        ff.insert(make_pair('T', 1));
//        ff.insert(make_pair('C', 2));
//        ff.insert(make_pair('G', 3));
//
//        map<int, int> m_map;
//        map<int, int>::iterator it;
//
//        for(int i=0; i<s.length()-9; i++) {
//
//            int sum = 0;
//            for(int j=i; j<i+10; j++) {
//                sum |= (ff[s[j]] << ((j-i)*2));
//            }
//
//            it = m_map.find(sum);
//            if(it != m_map.end()) {
//                if(it->second == 1){
//                    res.push_back(s.substr(i, 10));
//                }
//                it->second++;
//            } else {
//                m_map.insert(make_pair(sum, 1));
//            }
//        }
//        return res;
//    }
};

int main() {
    Solution s;
    s.findRepeatedDnaSequences("AAAAAGGGGGAAAAAGGGGGGAAAAACCCCTTT");
    return 0;
}


