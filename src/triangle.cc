#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector< vector<int> > &triangle) {
        int len = triangle.size();
        int **dp = new int *[len];

        int ite = 1;
        int ans = 0;
        dp[0] = new int [ite++];
        dp[0][0] = triangle[0][0];
        for (int i=1; i<triangle.size(); i++, ite++) {
            dp[i] = new int [ite];
            dp[i][0] = dp[i-1][0]+triangle[i][0];
            dp[i][ite-1] = dp[i-1][ite-2]+triangle[i][ite-1];
            for (int j=1; j<ite-1; j++)
                dp[i][j] = min(dp[i-1][j]+triangle[i][j], dp[i-1][j-1]+triangle[i][j]);
        }
        ans = dp[triangle.size()-1][0];
        for (int i=1; i<ite-1; i++) {
            ans = min(dp[triangle.size()-1][i], ans);
        }
        for (int i=0 ;i<triangle.size(); i++)
            delete [] dp[i];
        delete [] dp;
        return ans;
    }
};
int main() {
    int a[1] = {-1};
    int b[2] = {2, 3};
    int c[3] = {1, -1, -1};
    vector<int> va(a,a+1);
    vector<int> vb(b,b+2);
    vector<int> vc(c,c+3);

    vector< vector<int> > vv;
    vv.clear();
    vv.push_back(va);
    vv.push_back(vb);
    vv.push_back(vc);

    cout<<Solution().minimumTotal(vv)<<endl;
}
