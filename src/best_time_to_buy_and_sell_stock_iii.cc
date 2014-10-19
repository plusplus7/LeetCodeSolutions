#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        int *dp_left = new int [len];
        dp_left[0] = 0;
        int *dp_right = new int [len];
        dp_right[len-1] = 0;
        int l_min = prices[0];
        int r_max = prices[len-1];
        int ans = 0;
        for (int i=1; i<len; i++) {
            dp_left[i] = max(dp_left[i-1], prices[i]-l_min);
            l_min = min(l_min, prices[i]);
            ans = max(ans, dp_left[i]);
        }
        for (int i=len-2; i>=2; i--) {
            dp_right[i] = max(dp_right[i+1], r_max-prices[i]);
            r_max = max(r_max, prices[i]);
            ans = max(ans, dp_left[i-1] + dp_right[i]);
        }
        delete [] dp_left;
        delete [] dp_right;
        return ans;
    }
};

int main() {
    const int len = 13;
    int a[len] = {8,6,4,3,3,2,3,5,8,3,8,2,6};
    vector<int> p(a,a+len);
    cout<<Solution().maxProfit(p)<<endl;
}

