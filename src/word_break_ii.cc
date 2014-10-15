#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    struct Node {
        Node *next[26];
        int end;
        Node() {
            for (int i=0; i<26; i++) {
                next[i] = NULL;
            }
            end = 0;
        }
    };
    struct TrieTree {
        void build_tree() {
            root = new Node();
        }

        void insert(string strs)  {
            Node *tmp = root;
            for (int i=0; i<strs.length(); i++) {
                int index = get_val(strs[i]);
                if (tmp->next[index] == NULL)
                    tmp->next[index] = new Node();
                tmp = tmp->next[index];
                if (i == strs.length()-1)
                    tmp->end = 1;
            }
        }
  
        void tear_tree() {
            tear_down(root);
        }

        void tear_down(Node * cur) {
            if (cur == NULL)
                return ;
            for (int i=0; i<26; i++)
                tear_down(cur->next[i]);
            delete cur;
            cur = NULL;
        }

        int get_val(char c) {
            return c-'a';
        }

        vector<string> get_answer(string st) {
            ans_v.clear();
            s=st;
            int s_len = s.length();
            int * dp = new int [s_len+1];
            dp[s_len] = 1;
            vector<int> * dpx = new vector<int> [s_len+1];
            for (int i=0; i<=s_len; i++)
                dpx[i].clear();
            for  (int i=s_len-1; i>=0; i--) {
                Node *tmp = root;
                dp[i] = 0;
                for (int j=i; j<s_len; j++) {
                    int idx = get_val(s[j]);
                    if (tmp->next[idx] == NULL)
                        break;
                    if (tmp->next[idx]->end == 1) {
                        dpx[i].push_back(j+1);
                        dp[i] = dp[i] + dp[j+1];
                    }
                    tmp = tmp->next[idx];
                }
            }
            if (dp[0] == 0)
                return ans_v;
            get_ans_v(dpx, 0, "");
            delete [] dp;
            delete [] dpx; 
            tear_down(root);

            return ans_v;
        }

        void get_ans_v(vector<int> *dpx, int idx, string cur) {
            if (idx == s.length() && s.length() != 0) {
                ans_v.push_back(cur);
                return ;
            }
            for (int i=0; i<dpx[idx].size(); i++) {
                string tmp="";
                for (int j=idx; j<dpx[idx][i]; j++) {
                    tmp=tmp+s[j];
                }
                if (cur == "")
                    get_ans_v(dpx, dpx[idx][i], cur+tmp);
                else
                    get_ans_v(dpx, dpx[idx][i], cur+" "+tmp);
            }
        }
        string s;
        Node *root;
        vector<string> ans_v;
    };
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        TrieTree tt;
        tt.build_tree();
        for (unordered_set<string>::iterator ite=dict.begin(); ite != dict.end(); ite++)
            tt.insert(*ite);
        return tt.get_answer(s);
    }
};
int main(){
    const int d_len = 10;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; 
    //string s = "catsanddog";
    //string s = "";
    string dicts[] ={
        "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"
       // "cat", "cats", "and", "sand", "dog"
    };
    
    unordered_set<string> dict;
    dict.clear();
    for (int i=0; i<d_len; i++) {
        dict.insert(dicts[i]);
    }
    vector<string> ans = Solution().wordBreak(s, dict);

    for (int i=0; i<ans.size(); i++) {
        cout<<"# "<<ans[i]<<endl;
    }
}

