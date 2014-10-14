#include <iostream>
#include <vector>
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    bool on_line(Point a, Point b, Point c) {
        return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y) == 0;
    }
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 2)
            return points.size();
        int ans = 0;
        for (int i=0; i<points.size(); i++) {
            for (int j=i+1; j<points.size(); j++) {
                int cnt = 2;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    for (int k=0; k<points.size(); k++) {
                        if (i == k || j == k)
                            continue;
                        if (points[k].x == points[i].x && points[k].y == points[i].y)
                            cnt++;
                    }
                } else {
                    for (int k=0; k<points.size(); k++) {
                        if (i == k || j == k)
                            continue;    
                        if (on_line(points[i], points[j], points[k]) == true)
                            cnt++;  
                    }
                }
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};
int main() {
    vector<Point> pts;
    pts.clear();
    const int p_len = 3;
    int p[][2]={
       //{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}
            // {0, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}
        {1,1},{1,1},{1,1}
    };
    for (int i=0; i<p_len; i++)
        pts.push_back(Point(p[i][0], p[i][1]));
    cout<<Solution().maxPoints(pts)<<endl;
}
