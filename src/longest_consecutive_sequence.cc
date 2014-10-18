#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> f_hash;
        f_hash.clear();
        int ans = 1;
        int cur = 0;
        for (int i=0; i<num.size(); i++) {
            if (f_hash.find(num[i]) != f_hash.end())
                continue; 
            f_hash.insert(num[i]);
        }
        for (int i=0; i<num.size(); i++) {
            if (f_hash.find(num[i]) == f_hash.end())
                continue; 
            int t_ans = 1;
            cur = num[i]-1;
            while (f_hash.find(cur) != f_hash.end()) {
                t_ans++;
                f_hash.erase(cur);
                cur--;
            }
            cur = num[i]+1;
            while (f_hash.find(cur) != f_hash.end()) {
                t_ans++;
                f_hash.erase(cur);
                cur++;
            }
            ans = max(ans, t_ans);
        }
        return ans;
    }
};
int main() {
    const int len = 2;
    //int a[6] = {100, 4, 200, 1, 3, 2};
    int a[2] = {0, -1};
    vector<int> v(a, a+len);
    cout<<Solution().longestConsecutive(v)<<endl;
}
