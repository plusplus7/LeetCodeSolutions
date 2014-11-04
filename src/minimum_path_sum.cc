#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> > &grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        if (m == 0)
            return 0;

        int **dp = new int *[2];
        dp[0] = new int [m];
        dp[1] = new int [m];
        dp[0][0] = grid[0][0];

        for (int i=1; i<m; i++)
            dp[0][i] = dp[0][i-1]+grid[0][i];
        
        int f = 0;
        for (int i=1; i<n; i++) {
            dp[1-f][0] = dp[f][0]+grid[i][0];
            for (int j=1; j<m; j++) {
                dp[1-f][j] = min(dp[f][j], dp[1-f][j-1])+grid[i][j];
            }
            f = 1-f;
        }
        int ans = dp[f][m-1];
        delete [] dp[0];
        delete [] dp[1];
        delete [] dp;
        return ans;
    }
};
int main() {
    int a[4] = {1, 2, 3, 4};
    vector<int> va(a, a+4);
    vector< vector<int> > vva;
    vva.clear();
    vva.push_back(va);
    cout<<Solution().minPathSum(vva)<<endl;
}
