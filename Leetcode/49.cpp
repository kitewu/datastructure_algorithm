#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        map<string, vector<string> > mm;
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            mm[str].push_back(strs[i]);
        }
        for(map<string, vector<string> >::iterator it=mm.begin(); it!=mm.end(); it++)
            res.push_back(it->second);
        return res;
    }
};

int main(){
}
