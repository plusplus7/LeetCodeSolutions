#include <iostream>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int s_len = s.length();
        int *dp = new int [s_len];
        int **is_pal = new int *[s_len];
        for (int i=0; i<s_len; i++) {
            is_pal[i] = new int [s_len];
            for (int j=0; j<s_len; j++)
                is_pal[i][j] = 0;
        }
        for (int i=0; i<s_len; i++) {
            if (i+1 < s_len && s[i] == s[i+1])
                    is_pal[i][i+1] = 1;
            is_pal[i][i] = 1;
        } 
        for (int i=2; i<s_len; i++) {
            for (int j=0; j<s_len-i; j++) {
                if (s[j] == s[j+i] && is_pal[j+1][j+i-1] == 1)
                    is_pal[j][j+i] = 1;
            }
        }
        dp[0] = 0;
        for (int i=1; i<s_len; i++) {
            dp[i] = 0x7fffffff;
            for (int j=0; j<=i; j++) {
                if (is_pal[j][i] == 1) {
                    if (j == 0)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        return dp[s_len-1];
    }
};

int main() {
    cout<<Solution().minCut("aab")<<endl;
}
