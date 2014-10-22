#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int pr = 1;
        int ans = 1;
        for (int i=2; i<=n; i++) {
            ans = (pr*(4*i-2))/(i+1);
            pr = ans;
        }
        return ans;
    }
};

int main() {
    cout<<Solution().numTrees(3)<<endl;
}
