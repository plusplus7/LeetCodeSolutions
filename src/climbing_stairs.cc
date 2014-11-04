#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (mem[n] != 0)
            return mem[n];
        if (n <= 1)
            return mem[n]=1;
        return mem[n] = climbStairs(n-1)+climbStairs(n-2);
    }
    int mem[10000] = {0};
};
int main() {
    return cout<<Solution().climbStairs(10)<<endl;
}
