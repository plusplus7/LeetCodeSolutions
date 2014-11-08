#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        map<int, int> mp;
        map<int, int> pm;
        mp.clear();
        pm.clear();

        int lmp = 0;

        vector<int> asc;
        asc.clear();
        for (auto i : intervals) {
            asc.push_back(i.start);
            asc.push_back(i.end);
        }
        sort(asc.begin(), asc.end());

        for (auto i : asc) {
            if (mp.find(i) == mp.end()) {
                pm[lmp] = i;
                mp[i] = lmp++;
            }

            if (mp.find(i) == mp.end()) {
                pm[lmp] = i;
                mp[i] = lmp++;
            }
        }
        int *v = new int [lmp<<1];

        for (int i=0; i<lmp<<1; i++)
            v[i] = 0;
        for (auto i : intervals) {
            v[mp[i.start]<<1]++, v[mp[i.end+1]<<1]--;
        }

        vector<Interval> ans;
        ans.clear();
        int pr = -1, cnt = 0;
        for (int i=0; i<lmp; i++) {
            if (multi[i] == true)
                ans.push_back(Interval(pm[i], pm[i]));
            if (v[i] == 0)
                continue;
            if (pr == -1)
                pr = i;
            cnt = cnt+v[i];
            if (cnt == 0) {
                ans.push_back(Interval(pm[pr], pm[i]));
                pr = -1;
            }
        }
        return ans;
    }
};
int main(){}
