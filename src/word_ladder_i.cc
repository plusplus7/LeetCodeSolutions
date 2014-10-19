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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.find(start) == dict.end())
            dict.insert(start);
        if (dict.find(end) == dict.end())
            dict.insert(end);

        unordered_set<string> q[2];

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
                        if (cur == end)
                            out = true;
                        q[f^1].insert(cur);
                    }
                    cur[i] = ori;
                }
            }
            q[f].clear();
            f^=1;
            max_dep++;
        }
        return out?max_dep:0;
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
    int ans = Solution().ladderLength("hit", "cog", dict);
    cout<<ans<<endl;
}
