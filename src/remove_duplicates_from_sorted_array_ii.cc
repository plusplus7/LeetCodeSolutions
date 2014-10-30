#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ans = 0;
        int la = 0;
        int *ta = new int [n];
        for (int i=0; i<n; i++)
            ta[i] = A[i];
        for (int i=0; i<n; i++) {
            if (i >= 2 && ta[i] == ta[i-1] && ta[i] == ta[i-2]) 
                continue;
            ans++;
            A[la++] = A[i];
        }
        delete [] ta;
        return ans;
    }
};
int main(){
    int a[6] = {1,1,1,2,2,3};
    cout<<Solution().removeDuplicates(a, 6)<<endl;
    for (int i=0; i<5; i++)
        cout<<a[i]<<endl;
}
