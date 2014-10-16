#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i=0; i<n; i++)
            res = res^A[i];
        return res;
    }
};

int main() {
    int a[11] = {
        1,2,3,4,5,5,4,3,2,1,10
    };
    cout<<Solution().singleNumber(a, 11)<<endl;
}
