#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

typedef struct Trie_node   {
    bool exist; /// 标记该结点处是否构成单词
    struct Trie_node* next[26]; /// 指向各个子树的指针
    Trie_node() : exist(false) {
        memset(next, 0, sizeof(Trie_node*)*26);
    }
} TrieNode, *Trie;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res;
        if(sentence.length() == 0)
            return res;

        Trie root = new TrieNode();
        buildTrie(root, dict);

        stringstream ss(sentence);
        string temp;
        ss >> temp;
        res += findStr(root, temp);
        while(ss >> temp)
            res += " " + findStr(root, temp);
        return res;
    }

    void buildTrie(Trie root, const vector<string>& dict) {
        int index;
        for(int j=0; j<dict.size(); ++j) {
            Trie p = root;
            int i = 0;
            for(; i<dict[j].length(); ++i) {
                index = dict[j][i]-'a';
                if(p->next[index] == NULL)
                    p->next[index] = new TrieNode();
                p = p->next[index];
                if(i == dict[j].length()-1)
                    p->exist = true;
            }
        }
    }

    string findStr(Trie root, const string& str) {
        Trie p = root;
        int index;
        for(int i=0; i<str.length(); ++i) {
            index = str[i]-'a';
            if(p->next[index]) {
                if(p->next[index]->exist)
                    return str.substr(0, i+1);
                p = p->next[index];
            } else
                return str;
        }
        return str;
    }
};

int main() {
    Solution s;
    vector<string> vv;
    vv.push_back("cat");
    vv.push_back("bat");
    vv.push_back("rat");
    cout << s.replaceWords(vv, "the cattle was rattled by the battery");
    return 0;
}

