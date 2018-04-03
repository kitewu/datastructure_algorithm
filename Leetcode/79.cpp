#include<iostream>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if(search(i, j, 0, word, board))
                        return true;
                }
            }
        }
        return false;
    }

    bool search(int i, int j, int index, string &word, vector<vector<char> >& board) {
        if(index == word.size())
            return true;
        if(     i < 0 ||
                j < 0 ||
                i >= board.size()||
                j >= board[0].size() ||
                board[i][j] != word[index]) {
            return false;
        }
        char c = board[i][j];
        board[i][j] = '#';
        bool rst =  search(i + 1, j, index + 1, word, board) ||
                    search(i, j + 1, index + 1, word, board) ||
                    search(i, j - 1, index + 1, word, board) ||
                    search(i - 1, j, index + 1, word, board);
        board[i][j] = c;
        return rst;
    }
};

int main() {
}
