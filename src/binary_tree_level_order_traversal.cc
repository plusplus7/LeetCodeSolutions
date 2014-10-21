#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector< vector<int> > &ans, TreeNode *root, int dep) {
        if (root == NULL)
            return ;
        if (ans.size() == dep) {
            vector<int> tv;
            tv.clear();
            ans.push_back(tv);
        }
        ans[dep].push_back(root->val);
        dfs(ans, root->left, dep+1);
        dfs(ans, root->right, dep+1);
    }
    vector< vector<int> > LevelOrder(TreeNode *root) {
        vector< vector<int> > ans;
        ans.clear();
        dfs(ans, root, 0);
        return ans;
    }
};
