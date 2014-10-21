#include <iostream>

class Solution {
public:
    void dfs(vector< vector<int> > &ans, TreeNode *node, int dep) {
        if (node == NULL)
            return ;
        if (ans.size() == dep) {
            vector<int> tv;
            tv.clear();
            ans.push_back(tv);
        }
        ans[dep].push_back(node->val);
        dfs(ans, node->left, dep+1);
        dfs(ans, node->right, dep+1);
    }
    vector< vector<int> > levelOrderBottom(TreeNode *root) {
        vector< vector<int> > ans;
        ans.clear();
        dfs(ans, root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
