#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res = "";

        int l = 0;
        int c = 0;
        while (l < a.length() && l < b.length()) {
            res.push_back(((a[l]-'0'+b[l]-'0'+c)&1)+'0');
            c = (a[l]-'0'+b[l]-'0'+c)>>1;
            l++;
        }

        while (l < a.length()) {
            res.push_back(((a[l]-'0'+c)&1)+'0');
            c = (a[l]-'0'+c)>>1;
            l++;
        }

        while (l < b.length()) {
            res.push_back(((b[l]-'0'+c)&1)+'0');
            c = (b[l]-'0'+c)>>1;
            l++;
        }
        if (c == 1)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res==""?"0":res;
    }
};
int main() {
    cout<<Solution().addBinary("11","1")<<endl;
}
