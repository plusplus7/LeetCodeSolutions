#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> lv;
        lv.clear();
        vector<string> ans;
        ans.clear();

        int l_cnt = 0;
        for (int i=0; i<words.size(); ) {
            if (l_cnt+words[i].length()+(l_cnt!=0) > L) {
                string tar = "";
                if (l_cnt == L) {
                    for (auto str : lv) {
                        if (tar != "")
                            tar = tar+" ";
                        tar = tar+str;
                    }
                } else {
                    if (lv.size() == 1) {
                        tar = lv[0];
                        for (int j=tar.length(); j<L; j++)
                            tar = tar+" ";
                    } else {
                        int tmp = (L-l_cnt)/(lv.size()-1);
                        int tmp_r = (L-l_cnt)%(lv.size()-1);
                        for (auto str : lv) {
                            if (tar != "") {
                                tar = tar+" ";
                                for (int j=0; j<tmp; j++)
                                    tar = tar+" ";
                                if (tmp_r)
                                    tar = tar+" ", tmp_r--;
                            }
                            tar = tar+str;
                        }
                    }
                }
                l_cnt = 0;
                ans.push_back(tar);
                lv.clear();
            } else {
                if (l_cnt)
                    l_cnt++;
                l_cnt = l_cnt+words[i].length();
                lv.push_back(words[i]);
                i++;
            }
        }
        if (!lv.empty()) {
            string tar = "";
            for (auto str : lv) {
                if (tar != "")
                    tar = tar+" ";
                tar = tar+str;
            }
            for (int i=tar.length(); i<L; i++)
                tar = tar+" ";
            ans.push_back(tar);
        }
        return ans;
    }
};

int main() {
    string strs[7] = {
    //"This", "is", "an", "example", "of", "text", "justification."
    "Listen","to","many,","speak","to","a","few."
    };
    vector<string> tv(strs, strs+7);

    tv = Solution().fullJustify(tv, 6);

    for (auto i : tv) {
        cout<<"\""<<i<<"\""<<endl;
    }
}
