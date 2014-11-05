#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &og) {
        int n = og.size();
        if (n == 0)
            return 0;
        int m = og[0].size();
        if (m == 0)
            return 0;
        if (og[0][0] == 1)
            return 0;
        int **dp = new int *[2];
        dp[0] = new int [m];
        dp[1] = new int [m];
        

        dp[0][0] = 1;
        for (int i=1; i<m; i++) {
            if (og[0][i] == 1)
                dp[0][i] = 0;
            else
                dp[0][i] = dp[0][i-1];
        }

        int f = 0;
        for (int i=1; i<n; i++) {
            if (og[i][0] == 1)
                dp[1-f][0] = 0;
            else
                dp[1-f][0] = dp[f][0];
            for (int j=1; j<m; j++) {
                if (og[i][j]) {
                    dp[1-f][j] = 0;
                    continue;
                }
                dp[1-f][j] = (og[i-1][j]?0:dp[f][j]) + (og[i][j-1]?0:dp[1-f][j-1]);
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
    vector<int> tv;
    tv.push_back(0);
    tv.push_back(1);
    vector< vector<int> > cl;
    cl.push_back(tv);
    cout<<Solution().uniquePathsWithObstacles(cl)<<endl;
}
