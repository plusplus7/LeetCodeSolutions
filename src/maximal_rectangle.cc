#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector< vector<char> > &matrix) {
        if (matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        int **left = new int *[n];
        int **right = new int *[n];
        int **up = new int *[n];
        for (int i=0; i<n; i++) {
            left[i] = new int [m];
            right[i] = new int [m];
            up[i] = new int [m];
        }
        for (int i=0; i<n; i++) {
            int lo = -1, ro = m;
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == '0') {
                    left[i][j] = 0;
                    up[i][j] = 0;
                    lo = j;
                } else {
                    if (i == 0) {
                        left[i][j] = lo+1;
                        up[i][j] = 1;
                    } else {
                        left[i][j] = max(left[i-1][j], lo+1);
                        up[i][j] = up[i-1][j]+1;
                    }
                }
            }
            for (int j=m-1; j>=0; j--) {
                if (matrix[i][j] == '0') {
                    right[i][j] = m;
                    ro = j;
                } else {
                    if (i == 0)
                        right[i][j] = ro-1;
                    else
                        right[i][j] = min(right[i-1][j], ro-1);
                    ans = max(ans, up[i][j]*(right[i][j]-left[i][j]+1));
                }
            }
        }
        return ans;
    }
};
int main() {
    char tva[3][3]={
                    {'1','1','0'},
                    {'1','1','0'},
                    {'0','0','1'}
                    };
    vector< vector<char> > tv;
    tv.clear();
    for (int i=0; i<3; i++) {
        vector<char> tvb;
        tvb.clear();
        for (int j=0; j<3; j++) {
            tvb.push_back(tva[i][j]);
        }
        tv.push_back(tvb);
    }
    cout<<Solution().maximalRectangle(tv)<<endl;

}
