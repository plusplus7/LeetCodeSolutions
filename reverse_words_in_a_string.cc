#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> v_str;
        v_str.clear();
        string t_str = "";

        for (int i=0; i<=s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                if (t_str.length() == 0) {
                    continue;
                } else {
                   v_str.push_back(t_str);
                   t_str = "";
                }
            }
            else
                t_str = t_str+s[i];
        }

        string res = "";
        if (v_str.size() == 0) {
            s="";
            return ;
        }
        for (int i=v_str.size()-1; i>0; i--) {
            res=res+v_str[i]+" ";
        }
        res=res+v_str[0];
        s=res;
    }
};
int main() {
 //   string input = "   the   sky   is    blue   ";
    string input = "";
    Solution().reverseWords(input);
    cout<<input;
}
