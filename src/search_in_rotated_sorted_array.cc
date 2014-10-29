#include <iostream>

using namespace std;
class Solution {
public:
    int getMax(int A[], int n) {
        int l = 0, r = n-1;
        if (A[l] < A[r])
            return r;
        while (l < r) {
            int mid = (l+r)>>1;
            if (A[mid] >= A[l]) {
                if (A[mid+1] < A[l])
                    return mid;
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r-1;
    }
    int search(int A[], int n, int target) {
        int max_index = getMax(A, n), l = 0, r = 0;
        if (max_index == n-1)
            l = 0, r = max_index;
        else {
            if (A[0] > target)
                l = max_index+1, r = n-1;
            else
                l = 0, r = max_index;
        }
        while (l < r) {
            int mid = (l+r)>>1;
            if (A[mid] > target)
                r = mid-1;
            else if (A[mid] == target)
                return mid;
            else
                l = mid+1;
        }
        return A[l] == target?l:-1;
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
