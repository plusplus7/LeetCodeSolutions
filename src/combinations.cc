#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector< vector<int> > &ans, int n, int k, vector<int> cur) {
        if (n < k)
            return ;
        if (k == 0) {
            sort(cur.begin(), cur.end());
            ans.push_back(cur);
            return ;
        }
        if (n > k)
            dfs(ans, n-1, k, cur);
        cur.push_back(n);
        dfs(ans, n-1, k-1, cur);
    }
    vector<vector<int> > combine(int n, int k) {
        vector< vector<int> > ans;
        ans.clear();
        vector<int> tmp;
        tmp.clear();
        dfs(ans, n, k, tmp);
        return ans;
    }
};

int main() {
    vector< vector<int> > ans = Solution().combine(4, 2);
    for (auto i : ans) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
