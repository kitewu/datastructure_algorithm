#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        if(path.size() == 0)
            return res;
        vector<string> paths;
        getPaths(paths, path, 1);
        vector<string> ress;
        for(int i=0; i<paths.size(); i++) {
            if(paths[i] == "..") {
                if(ress.size() > 0)
                    ress.pop_back();
            } else if(paths[i] == ".")
                continue;
            else
                ress.push_back("/" + paths[i]);
        }
        for(int i=0; i<ress.size(); i++)
            res += ress[i];
        if(res == "")
            res = "/";
        return res;
    }

    void getPaths(vector<string> &paths, string &path, int start) {
        if(start >= path.length())
            return;
        while(path[start] == '/') start++;
        int i=start;
        for(; i<path.length(); i++) {
            if(path[i] == '/')
                break;
        }
        if(i != start){
            string str = path.substr(start, i-start);
            paths.push_back(str);
        }
        getPaths(paths, path, i+1);
    }
};

int main() {
    Solution s;
    s.simplifyPath("/..//123//");
}
