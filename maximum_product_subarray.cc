#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(int A[], int n) {
        int ans = A[0];
        int* dp_max = new int [n];
        int* dp_min = new int [n];

        dp_min[0] = A[0];
        dp_max[0] = A[0];

        for (int i=1; i<n; i++) {
            dp_max[i] = max(A[i], dp_max[i-1]*A[i]);
            dp_min[i] = min(A[i], dp_min[i-1]*A[i]);
            dp_max[i] = max(dp_max[i], dp_min[i-1]*A[i]);
            dp_min[i] = min(dp_min[i], dp_max[i-1]*A[i]);
            ans = max(ans, dp_max[i]);
        } 
        delete [] dp_max;
        delete [] dp_min;
        
        return ans;
    }
};


int main() {
    int a[4] = {-1, -2, -9, -6};
    cout<<Solution().maxProduct(a, 4)<<endl;
}
