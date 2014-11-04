#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1_len = word1.length();
        int w2_len = word2.length();

        if (w1_len == 0 || w2_len == 0)
            return w1_len?w1_len:w2_len;

        int **dp = new int *[w1_len+1];

        for (int i=0; i<=w1_len; i++) {
            dp[i] = new int [w2_len+1];
        }

        for (int i=0; i<=w1_len; i++)
            dp[i][0] = i;
        for (int i=0; i<=w2_len; i++)
            dp[0][i] = i;
        for (int i=1; i<=w1_len; i++) {
            for (int j=1; j<=w2_len; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        return dp[w1_len][w2_len];
    }
};
int main() {
    cout<<Solution().minDistance("sea", "eat")<<endl;;
}
