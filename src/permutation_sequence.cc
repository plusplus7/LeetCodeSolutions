#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string ans = "";
        bool v[12];
        memset(v, false, sizeof(v));

        for (int i=1; i<=n; i++) {
            int t = k/fact[n-i];
            k = k-t*fact[n-i];
            for (int j=1; j<=12; j++) {
                if (!v[j]) {
                    t--;
                    if (t == -1) {
                        v[j] = true;
                        ans.push_back(j+'0');
                        break;
                    }
                }
                    
            }
        }
        return ans;
    }
};

int main() {
    cout<<Solution().getPermutation(3, 3)<<endl;
}
