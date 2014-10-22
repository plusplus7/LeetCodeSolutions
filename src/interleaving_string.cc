#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_len = s1.length();
        int s2_len = s2.length();
        int s3_len = s3.length();
        if (s1_len+s2_len != s3_len)
            return false;

        int **dp = new int *[s1_len+1];
        
        for (int i=0; i<s1_len+1; i++) {
            dp[i] = new int [s2_len+1]; 
            for (int j=0; j<s2_len+1; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i=0; i<=s1_len; i++) {
            for (int j=0; j<=s2_len; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0 && s3[j-1] == s2[j-1])
                    dp[i][j] = dp[i][j-1];
                else if (j == 0 && s3[j-1] == s1[i-1])
                    dp[i][j] = dp[i-1][j];
                else {
                    if (s3[i+j-1] == s1[i-1])
                        dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    if (s3[i+j-1] == s2[j-1])
                        dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1_len][s2_len];
    }
};

int main() {
    cout<<Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac");
}
