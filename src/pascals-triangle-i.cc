#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRow) {
        vector< vector<int> > res;
        res.clear();
        for (int cnt=0; cnt<numRow; cnt++) {
            vector<int> ans;
            ans.clear();
            ans.push_back(1);
            int a = 1, b = 1;
            for (int i=1; i<=cnt; i++) {
                a = (double)b*((double)cnt-i+1)/(double)i;
                b = a;
                ans.push_back(a);
            }
            res.push_back(ans); 
        }
        return res;
    }
};
int main() {
}
