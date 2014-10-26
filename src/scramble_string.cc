#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        if (s1.length() <= 1)
            return s1 == s2;

        string t1 = s1;
        string t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2)
            return false;
        

        for (int mid = 1; mid < s1.size(); mid++) {
            if (isScramble(s1.substr(0, mid), s2.substr(0, mid)) == true
             && isScramble(s1.substr(mid, s1.length()-mid), s2.substr(mid, s2.length()-mid)))
                return true;

            if (isScramble(s1.substr(mid, s1.length()-mid), s2.substr(0, s2.length()-mid)) == true
             && isScramble(s1.substr(0, mid), s2.substr(s2.length()-mid, mid)))
                return true;
        }
        return false;
    }
};
int main() {
    cout<<Solution().isScramble("great", "rgeat")<<endl;
}
