#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int l = strlen(s);
        int ans = 0;
        while (l != 0 && s[l-1] == ' ')
            l--;
        while (l != 0 && s[l-1] != ' ') ans++, l--;
        return ans;
    }
};
int main() {
    cout<<Solution().lengthOfLastWord("asdf asdfasd")<<endl;
}
