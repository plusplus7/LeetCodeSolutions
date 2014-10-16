#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {                                
        int cnt[32];
        memset(cnt, 0, sizeof(cnt));
        for (int i=0; i<n; i++) {
            int ite = 1;
            for (int j=0; j<32; j++, ite<<=1) {
                if (A[i]&ite)
                    cnt[j]++;
            }
        }
        int res = 0;
        for (int j=0; j<32; j++) {
            if (cnt[j]%3) {
                res+=1<<j;
            }
        }
        return res;
    }
};

int main() {
    int a[10] = {
    333,222,333,222,333,222,111,111,111,423
    };
    cout<<Solution().singleNumber(a, 10)<<endl;
}
