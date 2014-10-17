#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void get_ans(vector< vector<string> > &res, vector<string> &cur, int ind, int **is_pal, int s_len, string &s) {
        if (ind == s_len) {
            res.push_back(cur);
            return ;
        }
        for (int i=ind; i<s_len; i++) {
            if (is_pal[ind][i] == 1) {
                cur.push_back(s.substr(ind, i-ind+1));
                get_ans(res,cur,i+1,is_pal, s_len, s);
                cur.pop_back();
            }
        }
    }

    vector< vector<string> > partition(string s) {
        int s_len = s.length();
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
        vector<string> cur;
        vector< vector<string> > result;
        result.clear();
        cur.clear();

        get_ans(result, cur, 0, is_pal, s_len, s);

        for (int i=0; i<s_len; i++)
            delete [] is_pal[i];
        delete [] is_pal;
        return result;
    }
};

int main() {
    vector<vector<string> > ans = Solution().partition("aab");;
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
