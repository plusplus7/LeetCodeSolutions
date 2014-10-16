#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int res = 1;
        vector<int> candies;
        candies.clear();
        candies.push_back(1);
        for (int i=1; i<ratings.size(); i++) {
            if (ratings[i-1] < ratings[i])
                candies.push_back(candies[i-1]+1);
            else
                candies.push_back(1);
        }
        res = candies[ratings.size()-1];
        for (int i=ratings.size()-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
                candies[i]=candies[i+1]+1;
            res+=candies[i];
        }
        return res;
    }
};

int main() {
    vector<int> v;
    v.clear();
    int a[10] = {1,2,3,4,1,2,3,4,1,2};
    for (int i=0; i<10; i++)
        v.push_back(a[i]);
    cout<<Solution().candy(v)<<endl;
}
