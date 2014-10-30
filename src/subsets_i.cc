#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector< vector<int> > ans;
        ans.clear();
        int len = 1<<S.size();
        for (int i=0; i<len; i++) {
            vector<int> tmp;
            tmp.clear();
            for (int j=0; j<S.size(); j++) {
                if (i&(1<<j)) {
                    tmp.push_back(S[j]);
                }
            }
            sort(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};
int main(){}
