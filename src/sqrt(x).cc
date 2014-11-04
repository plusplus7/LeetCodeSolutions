#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        double tmp = 1.0;
        while (true) {
            double nt = tmp/2.0+(double)x/(2.0*tmp);
            if (fabs(nt-tmp) < 1e-7)
                break;
            tmp = nt;
        }
        int ans = tmp;
        if (ans*ans > x) ans--;
        return ans;
    }
};
int main() {
    cout<<Solution().sqrt(15)<<endl;
}
