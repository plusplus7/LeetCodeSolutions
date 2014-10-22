#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool judge(string &s, int a, int b, int c) {
        int s_len = s.length();
        if (c >= s_len-1 || b >= s_len-1 || a >= s_len-1)
            return false;
        int ite = 0;
        for (int i=0; i<s_len; i++) {
            if (s[i] == '0' && ite == 0 && i != a && i != b && i != c && i != s_len-1)
                return false;
            ite = ite*10+s[i]-'0';
            if (i == a || i == b || i == c) {
                if (ite > 255)
                    return false;
                ite = 0;
            }
        }
        if (ite > 255)
            return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        ans.clear();
        if (s.length() > 12)
            return ans;
        for (int i=0; i<3; i++) {
            for (int j=i+1; j<i+4; j++) {
                for (int k=j+1; k<j+4; k++) {
                    if (judge(s, i, j, k) == true) {
                        string tar = "";
                        for (int m=0; m<s.length(); m++) {
                            tar = tar+s[m];
                            if (i == m || j == m || k == m)
                                tar = tar+'.';
                        }
                        ans.push_back(tar);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> vs = Solution().restoreIpAddresses("0000");
    for (auto i : vs) 
        cout<<i<<endl;
}
