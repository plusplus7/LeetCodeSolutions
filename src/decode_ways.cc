#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int s_len = s.length();
        if (s_len == 0)
            return 0;
        int *dp = new int [s_len];
        if (s[0] == '0')
            return 0;
        dp[0] = 1;
        if (s[1] != '0')
            dp[1] = ((s[1]<='6'&&s[0]=='2') || (s[0] == '1'))+1;
        else
            dp[1] = (s[0]<='2');
        if (dp[1] == 0)
            return 0;
        for (int i=2; i<s_len; i++) {
            if (s[i] == '0') {
                if (s[i-1] > '2' || s[i-1] == '0')
                    return 0;
                else 
                    dp[i] = dp[i-2];
            } else {
                dp[i] = dp[i-1];
                if ((s[i]<='6'&&s[i-1]=='2') || (s[i-1] == '1'))
                    dp[i] = dp[i]+dp[i-2];
            }
            if (dp[i] == 0)
                return 0;
        }
        return dp[s_len-1];
    }
};
int main() {
    cout<<Solution().numDecodings("12")<<endl;
}
