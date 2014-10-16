#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r =  num.size()-1;
        if (num[l] < num[r])
            return num[l];
        while (l < r) {
            int mid = (l+r)>>1;
            if (num[mid] >= num[l]) {
                if (num[mid+1] < num[l])
                    return num[mid+1];
                
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return num[r];
    }
};

int main() {
    const int a_len = 7;
    int a[a_len] = {
        4,5,6,7,0,1,2
    };
    vector<int> v;
    v.clear();
    for (int i=0; i<a_len; i++) {
        v.push_back(a[i]);
    }
    cout<<Solution().findMin(v)<<endl;;
}
