#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class Solution {
public:
    int max(int a, int b) {
        return a>b?a:b;
    }
    int largestRectangleArea(vector<int> &height) {
        stack<int> stk;
        while (!stk.empty())
            stk.pop();
        int ans = 0;
        for (int i=0; i<height.size(); i++) {
            if (!stk.empty() && height[i] < height[stk.top()]) {
                int t = stk.top();
                stk.pop();
                if (stk.empty())
                    ans = max(ans, height[t]*i);
                else
                    ans = max(ans, height[t]*(i-stk.top()-1));
                i--;
            } else {
                stk.push(i);
            }
        }
        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            if (stk.empty())
                ans = max(ans, height[t]*height.size());
            else
                ans = max(ans, height[t]*(height.size()-stk.top()-1));
        }
        return ans;
    }
};
int main() {
    int a[6] = {2, 1, 5, 6, 2, 3};
    vector<int> tv(a, a+6);
    cout<<Solution().largestRectangleArea(tv)<<endl;
}
