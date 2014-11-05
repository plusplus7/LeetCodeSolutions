#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, x = 0, y = 0;
        vector< vector<int> > ans(n, vector<int>(n, 0));
        if (n == 0)
            return ans;
        ans[0][0] = 1;
        for (int i=2; i<=n*n; i++) {
            int tx = 0, ty = 0;
            while (true) {
                tx = x+dir[d][0];
                ty = y+dir[d][1];
                if (tx >= n || tx < 0 || ty >= n || ty < 0 || ans[tx][ty] != 0)
                    d = (d+1)&3;
                else
                    break;
            }
            ans[tx][ty] = i;
            x = tx, y = ty;
        }
        return ans;
    }
};

int main() {
    auto tmp = Solution().generateMatrix(3);
    for (auto i : tmp) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
