class Solution {
public:
    vector<int> garyCode(int n) {
        vector<int> ans;
        ans.clear();
        for (int i=0; i<(1<<n); i++)
            ans.push_back(i^(i>>1));
        return ans;
    }
};
