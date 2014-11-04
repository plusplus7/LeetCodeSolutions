#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0)
            return ;
        int *col = new int [matrix.size()];
        int *row = new int [matrix[0].size()];

        for (int i=0; i<matrix.size(); i++)
            col[i] = 1;
        for (int i=0; i<matrix[0].size(); i++)
            row[i] = 1;

        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<matrix[i].size(); j++)
                if (matrix[i][j] == 0) {
                    col[i] = 0;
                    row[j] = 0;
                }
        for (int i=0; i<matrix[0].size(); i++)
            if (row[i] == 0)
                for (int j=0; j<matrix.size(); j++)
                    matrix[j][i] = 0; 
        for (int i=0; i<matrix.size(); i++)
            if (col[i] == 0)
                for (int j=0; j<matrix[i].size(); j++)
                    matrix[i][j] = 0;
    }
};
int main(){}
