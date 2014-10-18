#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n,m;
    void visit(vector< vector<char> > &board, int x, int y) {
        if (x < n-1 && board[x+1][y] == 'O') {
            board[x+1][y] = '7';
            visit(board, x+1, y);
        }
        if (y < m-1 && board[x][y+1] == 'O') {
            board[x][y+1] = '7';
            visit(board, x, y+1);
        }
        if (y > 1 && board[x][y-1] == 'O') {
            board[x][y-1] = '7';
            visit(board, x, y-1);
        }
        if (x > 1 && board[x-1][y] == 'O') {
            board[x-1][y] = '7';
            visit(board, x-1, y);
        }
    }
    void solve(vector< vector<char> > &board) {
        if (board.size() < 2)
            return ;
        if (board[0].size() < 2)
            return ;
        n = board.size();
        m = board[0].size();
        for (int i=1; i<n-1; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '7';
                visit(board, i, 0);
            }
        }
        for (int i=1; i<n-1; i++) {
            if (board[i][m-1] == 'O') {
                board[i][m-1] = '7';
                visit(board, i, m-1);
            }
        }
        for (int i=0; i<m; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = '7';
                visit(board, 0, i);
            }
        }
        for (int i=0; i<m; i++) {
            if (board[n-1][i] == 'O') {
                board[n-1][i] = '7';
                visit(board, n-1, i);
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == '7') {
                    board[i][j] = 'O';
                    continue;
                }
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    char g[4][4] = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
    };
    vector<char> t_x;
    vector< vector<char> > in;
    
    in.clear();
    for (int i=0; i<4; i++) {
        t_x.clear();
        for (int j=0; j<4; j++)
            t_x.push_back(g[i][j]);
        in.push_back(t_x);
    }
    Solution().solve(in);
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout<<in[i][j]<<" ";
        }
        cout<<endl;
    }
}

