#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        int ans = 0;
        int pm = prices[0];
        for (int i=1; i<prices.size(); i++) {
            ans = max(ans, prices[i]-pm);
            pm = min(pm, prices[i]);
        }
        return ans;
    }
};

int main() {
    const int len = 3;
    int a[len] = {2, 1, 4};
    vector<int> p(a,a+len);
    cout<<Solution().maxProfit(p)<<endl;
}
