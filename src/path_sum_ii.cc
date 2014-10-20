#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void dfs(vector< vector<int> > &ans, TreeNode *root, int sum, vector<int> tv) {
        if (root == NULL)
            return ;
        sum-=root->val;
        tv.push_back(root->val);
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            ans.push_back(tv);
        }
        dfs(ans, root->left, sum, tv);
        dfs(ans, root->right, sum, tv);
    }
    vector< vector<int> > pathSum(TreeNode *root, int sum) {
        vector< vector<int> > ans;
        ans.clear();
        if (root == NULL)
            return ans;
        vector<int> tv;
        tv.clear();
        dfs(ans, root, sum, tv);
        return ans;
    }        
};
int main(){}

