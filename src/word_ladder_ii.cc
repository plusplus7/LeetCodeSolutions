#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        if (dict.find(start) == dict.end())
            dict.insert(start);
        if (dict.find(end) == dict.end())
            dict.insert(end);

        vector< vector<string> > ans;
        unordered_map<string, unordered_set<string> > parent;
        unordered_set<string> q[2];

        ans.clear();
        parent.clear();
        q[0].clear();
        q[1].clear();

        int f = 0;
        q[f].insert(start);
        bool out = false;
        int max_dep = 1;
        while (!q[f].empty() && !out) {
            for (auto cur : q[f])
                dict.erase(cur);
            for (auto cur : q[f]) {
                string oric = cur;
                for (int i=0; i<cur.length(); i++) {
                    char ori = cur[i];
                    for (char j='a'; j<='z'; j++) {
                        if (j == ori)
                            continue;
                        cur[i] = j;
                        if (dict.find(cur) == dict.end())
                            continue;
                        if (parent.find(cur) == parent.end()) {
                            parent[cur] = unordered_set<string>();
                            parent[cur].clear();
                        }
                        if (cur == end)
                            out = true;
                        parent[cur].insert(oric);
                        q[f^1].insert(cur);
                    }
                    cur[i] = ori;
                }
            }
            q[f].clear();
            f^=1;
            max_dep++;
        }

        vector<string> tv;
        tv.clear();
        tv.resize(max_dep);
        dfs(parent, tv, ans, end, max_dep-1);
        return ans;
    }
    void dfs(unordered_map<string, unordered_set<string> > &parent, vector<string> tv, vector< vector<string> > &ans, string curr, int cur_dep) {
        tv[cur_dep] = curr;
        if (cur_dep == 0) {
            ans.push_back(tv);
            return ;
        }
        for (auto i : parent[curr]) {
            dfs(parent, tv, ans, i, cur_dep-1);
        }
    }
};

int main() {
    const int d_len = 5;
    string s_dicts[d_len] = {
       // "a","b","c"
        "hot","dot","dog","lot","log"
    };
    unordered_set<string> dict;
    dict.clear();
    for (int i=0; i<d_len; i++) {
        dict.insert(s_dicts[i]);
    }
    vector< vector<string> > ans = Solution().findLadders("hit", "cog", dict);
    for (auto i : ans) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
