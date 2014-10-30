#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector< vector<char> > &board, int x, int y, string &word, int ind) {
        if (ind == word.length())
            return true;
        if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0)
            return false;
        if (board[x][y] == word[ind])
            ind++;
        else
            return false;
        char mem = board[x][y];
        board[x][y] = '%';
        if (dfs(board, x+1, y, word, ind) == true)
            return true;
        if (dfs(board, x-1, y, word, ind) == true)
            return true;
        if (dfs(board, x, y+1, word, ind) == true)
            return true;
        if (dfs(board, x, y-1, word, ind) == true)
            return true;
        board[x][y] = mem;
        return false;
    }
    bool exist(vector< vector<char> > &board, string word) {
        if (word == "")
            return true;
        if (board.size() == 0)
            return false;
        if (board[0].size() == 0)
            return false;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (dfs(board, i, j, word, 0) == true)
                    return true;
            }
        }
        return false;
    }
};
int main(){}
