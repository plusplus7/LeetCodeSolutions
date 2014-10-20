#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.clear();
        ans.push_back(1);
        int a = 1, b = 1;
        for (int i=1; i<=rowIndex; i++) {
            a = (double)b*((double)rowIndex-i+1)/(double)i;
            b = a;
            ans.push_back(a);
        }
        return ans; 
    }
};
int main() {
    vector<int> ans = Solution().getRow(4);
    for (auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}
