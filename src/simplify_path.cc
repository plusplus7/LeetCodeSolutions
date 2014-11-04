#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int lp = path.length();
        if (lp == 0)
            return "/";
        if (path[lp-1] != '/')
            path = path+'/', lp++;
        deque<string> dq;
        dq.clear();
        string tmp = "";
        for (int i=1; i<lp; i++) {
            if (path[i] == '/') {
                if (tmp == "")
                    continue;
                else {
                    if (tmp == ".." && dq.size() != 0)
                        dq.pop_front();
                    else if (tmp != ".." && tmp != ".")
                        dq.push_front(tmp);
                    tmp = "";
                }
            }
            else
                tmp = tmp+path[i];
        }
        string ans = "";
        while (!dq.empty()) {
            ans = ans+"/"+dq.back();
            dq.pop_back();
        }
        return ans==""?"/":ans;
    }
};
int main() {
    string in;
    cin>>in;
    cout<<Solution().simplifyPath(in)<<endl;
}
