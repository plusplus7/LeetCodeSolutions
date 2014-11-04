#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int ld = digits.size()-1;
        while (ld >= 0 && digits[ld] == 9) {
            digits[ld--] = 0;
        }
        if (ld == -1) {
            digits[0] = 1;
            digits.push_back(0);
        } else {
            digits[ld]++;
        }
        return digits;
    }
};
int main(){}
