#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        int ans = 0;
        int pr = prices[0];
        for (int i=1; i<prices.size()-1; i++) {
            if (prices[i] < prices[i-1])
                pr = prices[i];
            if (prices[i] >= prices[i-1] && prices[i+1] < prices[i]) {
                ans = ans+prices[i]-pr;
                pr = prices[i+1];
            }
        }
        if (pr < prices.back()) {
            ans = ans+prices.back()-pr;
        }
        return ans;
    }
};

int main() {
    const int len = 13;
    int a[len] = {8,6,4,3,3,2,3,5,8,3,8,2,6};
    vector<int> p(a,a+len);
    cout<<Solution().maxProfit(p)<<endl;
}
