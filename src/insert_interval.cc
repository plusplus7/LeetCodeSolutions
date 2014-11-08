#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		vector<Interval> ans;
		int i = 0;

		while (i < intervals.size() && newInterval.start > intervals[i].end)
            ans.push_back(intervals[i++]);

		if (i < intervals.size())
			newInterval.start = min(newInterval.start, intervals[i].start);

		while (i < intervals.size() && newInterval.end >= intervals[i].start)
			newInterval.end = max(newInterval.end, intervals[i++].end);

		ans.push_back(Interval(newInterval.start, newInterval.end));
		ans.insert(ans.end(), intervals.begin()+i, intervals.end());
		return ans;
	}
};
int main() {
}
