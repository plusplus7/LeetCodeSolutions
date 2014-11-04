class Solution {
public:
    void sortColors(int A[], int n) {
        int color[3];
        memset(color, 0, sizeof(color));
        for (int i=0; i<n; i++)
            color[A[i]]++;
        for (int i=0, j=0; i<n; i++) {
            while (color[j] == 0)
                j++;
            A[i] = j;
            color[j]--;
        }
    }
};
