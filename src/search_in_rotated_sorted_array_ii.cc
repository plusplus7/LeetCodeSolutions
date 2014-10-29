#include <iostream>

using namespace std;
class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i=0; i<n; i++) {
            if (A[i] == target)
                return true;
        }
        return false;
    }
};
int main() {
    /*int a[7] = {4,5,6,7,0,1,2};
    for (int i=0; i<8; i++)
    cout<<Solution().search(a, 7, i)<<" "<<i<<endl;;
    */
    int a[6] = {3,4,5,6,1,2};
    cout<<Solution().search(a, 6, 2)<<endl;
}
