#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(const char *str) {
        int tmp = 0;
        if (str == NULL)
            return false;;
        while (*str == ' ')
            str++;
        string strs(str);
        while (strs.back() == ' ')
            strs.pop_back();

        if (strs.length() == 0)
            return false;
        const char *s = strs.c_str();
        int s_len = strlen(s);

        if ((s[0] == '.' && s_len == 1)
         || (s[0] == '-' && s[1] == '.' && s_len == 2)
         || s[0] == 'e' || s[s_len-1] == 'e'
         || s[0] == 'E' || s[s_len-1] == 'E'
         || s[s_len-1] == '-'
         || s[s_len-1] == '+')
            return false;
        for (int i=0; s[i]; i++)
            if ((s[i] == '-' && i != 0 && s[i-1] != 'e' && s[i-1] != 'E') || (s[i] == '+' && i != 0 && s[i-1] != 'e' && s[i-1] != 'E') || s[i] == ' ' || (s[i] != 'E' && (s[i] <= 'Z' && s[i] >= 'A')) || (s[i] != 'e' && (s[i] <= 'z' && s[i] >= 'a')))
                return false;
        tmp = 1;
        if (s[0] == '-' && (s[1] == 'e' || s[1] == 'E'))
            return false;
        if (s[0] == '+' && (s[1] == 'e' || s[1] == 'E'))
            return false;
        if (s[0] == '.' && (s[1] == 'e' || s[1] == 'E'))
            return false;
        for (int i=0; s[i]; i++) {
            if (s[i] == '.' && s[i+1] == '-')
                return false;
            if (s[i] == '.' && tmp)
                tmp = 0;
            else if (s[i] == '.' && !tmp)
                return false;
        }
        tmp = 1;
        for (int i=0; s[i]; i++) {
            if (s[i] == '.' && !tmp)
                return false;
            if (s[i+1] == '.' && (s[i] == 'e' || s[i] == 'E'))
                return false;
            if ((s[i] == 'e' || s[i] == 'E') && tmp)
                tmp = 0;
            else if ((s[i] == 'e' || s[i] == 'E') && !tmp)
                return false;
        }
        return true;
    }
};
int main(){}
