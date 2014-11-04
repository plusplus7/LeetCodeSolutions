#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int t_len = T.length();
        int s_len = S.length();
        if (t_len > s_len)
            return "";

        int cnt[256];
        int tar[256];
        int ct_cnt = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(tar, 0, sizeof(tar));

        for (int i=0; i<t_len; i++) {
            tar[T[i]]++;
        }
        int start = 0;
        int ans = 0x7fffffff;
        string ans_str = "";
        for (int i=0; i<s_len; i++) {
            int tmp = S[i];
            if (tar[tmp] > cnt[tmp]) {
                ct_cnt++;
            }
            cnt[tmp]++;
            if (ct_cnt == t_len) {
                while (true) {
                    if (cnt[S[start]] > tar[S[start]]) {
                        cnt[S[start]]--;
                        start++;
                    } else {
                        break;
                    }
                }
                if (ans > i-start+1) {
                    ans_str = S.substr(start, i-start+1);
                    ans = i-start+1;
                }
                cnt[S[start]]--;
                start++;
                ct_cnt--;
            }
        }
        return ans_str;
    }
};
int main() {
    cout<<Solution().minWindow("ADOBECODEBANC", "ABC")<<endl;
}
