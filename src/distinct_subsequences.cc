#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int s_len = S.length();
        int t_len = T.length();
        if (!s_len || !t_len)
            return 0;
        int **dp = new int *[s_len];
        dp[0] = new int [t_len];
        dp[0][0] = S[0] == T[0];
        for (int i=1; i<s_len; i++) {
            dp[i] = new int [t_len];
            dp[i][0] = (S[i] == T[0])+dp[i-1][0];
        }
        for (int i=1; i<t_len; i++) {
            dp[0][i] = 0;
        }
        for (int i=1; i<s_len; i++) {
            for (int j=1; j<t_len; j++) {
                dp[i][j] = dp[i-1][j];
                if (S[i] == T[j])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        int ans = dp[s_len-1][t_len-1];
        for (int i=0; i<s_len; i++)
            delete [] dp[i];
        delete [] dp;
        return ans;
    }
};

int main() {
    cout<<Solution().numDistinct("rabbbit", "rabbit")<<endl;
}
