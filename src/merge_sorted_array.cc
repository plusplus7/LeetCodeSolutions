class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int la = m+n-1;

        while (la && n && m) {
            A[la--] = B[n-1]>A[m-1]?B[--n]:A[--m];
        }
        while (n--)
            A[la--] = B[n];
        while (m--)
            A[la--] = A[m];
    
    }
};
