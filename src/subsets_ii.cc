#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &ans, vector<int> &S, int ind, vector<int> curr) {
        ans.push_back(curr);
        for (int i = ind; i<S.size(); i++) {
            if (i > ind && S[i] == S[i-1])
                continue;
            curr.push_back(S[i]);
            dfs(ans, S, i+1, curr);
            curr.pop_back();
        }
    }
    vector< vector<int> > subsetsWithDup(vector<int> &S) {
        vector< vector<int> > ans;
        sort(S.begin(), S.end());
        dfs(ans, S, 0, vector<int>());
        return ans;
    }
};

int main() {
    int a[3] = {1,2,2};
    vector<int> tv(a, a+3);
    vector< vector<int> > vv = Solution().subsetsWithDup(tv);
    for (auto i : vv) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
