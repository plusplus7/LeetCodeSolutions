#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 1)
            return gas[0] >= cost[0]?0:-1;
        int ans = -1;
        int sum = 0;
        int v_len = gas.size();
        for (int i=0; i<v_len*2; i++) {
            sum = sum+gas[i%v_len]-cost[i%v_len];
            if (sum < 0) {
                sum = 0;
                ans = i+1;
            }
        }
        return ans >= v_len?-1:ans;
    }
};
int main() {
    const int len = 2;
    int a[10] = {2, 4};
    int b[10] = {3, 4};
    vector<int> va, vb;
    va.clear();
    vb.clear();
    for (int i=0; i<len; i++) {
        va.push_back(a[i]);
        vb.push_back(b[i]);
    }
    cout<<Solution().canCompleteCircuit(va, vb)<<endl;
}
