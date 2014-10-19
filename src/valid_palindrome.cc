#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int lr = s.length();
        int l = 0, r = lr-1;
        while (l < r) {
            if (!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9'))) {
                l++;
                continue;
            }
            if (!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9'))) {
                r--;
                continue;
            }
            if (s[l] != s[r] && s[l] != s[r]-32 && s[l] != s[r]+32)
                return false;
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    cout<<Solution().isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<Solution().isPalindrome("race a car")<<endl;
}
