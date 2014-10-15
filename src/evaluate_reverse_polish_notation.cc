#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
    public:
    int stoi(string tstr) {
        return atoi(tstr.c_str());
    }

    string itos(int i) {
        stringstream ss;
        ss<<i;
        string ts=ss.str();
        return ts;
    }
    int calculate(string a, string b, string op) {
        if (op[0] == '+')
            return stoi(a)+stoi(b);
        if (op[0] == '-')
            return stoi(a)-stoi(b);
        if (op[0] == '*')
            return stoi(a)*stoi(b);
        if (op[0] == '/')
            return stoi(a)/stoi(b);
        return -1;
    }
    int evalRPN(vector<string> &tokens) {                                    
        stack<string> stk;
        while (!stk.empty())
            stk.pop();
        
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i].length() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')) {
                stk.push(tokens[i]);
            } else {
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                stk.push(itos(calculate(b, a, tokens[i])));
            }
        }
        return stoi(stk.top());
    }
};

int main() {
    vector<string> tok;
    tok.clear();
    const int s_len = 3;
    string st[s_len]={
        //"2", "1", "+", "3", "*"
        //"4", "13", "5", "/", "+"
        "3","-4","+"
    };
    for (int i=0; i<s_len; i++)
        tok.push_back(st[i]);
    cout<<Solution().evalRPN(tok)<<endl;
}
