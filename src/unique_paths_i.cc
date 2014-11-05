#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double get_ans(double m, double n) {
        double ans = 1.0;
        for (double i=1.0; i<=m-1.0; i++)
            ans = ans*((n-1.0+i)/i);
        return ans; 
    }
    int uniquePaths(int m, int n) {
        return get_ans(m, n);
    }
};
int main() {
            cout<<Solution().get_ans(100, 1)<<endl;;
    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5; j++) {
            cout<<Solution().get_ans(i, j)<<" ";
        }
        cout<<endl;
    }
}
