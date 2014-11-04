#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector< vector<int> > &matrix, int target) {
        int l = 0, r = matrix.size();
        int col = 0;
        while (l < r) {
            int mid = l+r>>1;
            if (matrix[mid][0] > target)
                r = mid;
            else if (matrix[mid][0] < target) {
                col = mid;
                l = mid+1;
            }
            else
                return true;
        }
        l = 0;
        r = matrix[col].size()-1;
        while (l <= r) {
            int mid = l+r>>1;
            if (matrix[col][mid] > target)
                r = mid-1;
            else if (matrix[col][mid] < target)
                l = mid+1;
            else
                return true;
        }
        return false;
    }
};

int main() {
    int a[3][4] = { 
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };

    vector< vector<int> > vec;
    vec.clear();
    for (int i=0; i<3; i++) {
        vector<int> tv;
        tv.clear();
        for (int j=0; j<4; j++)
            tv.push_back(a[i][j]);
        vec.push_back(tv);
    }
    cout<<Solution().searchMatrix(vec, 11)<<endl;
}
