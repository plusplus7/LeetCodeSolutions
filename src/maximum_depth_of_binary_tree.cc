#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void dfs(TreeNode *root, int dep) {
        if (root == NULL)
            return ;
        if (root->left == NULL && root->right == NULL) {
            ans = max(ans, dep);
            return ;
        }
        dfs(root->left, dep+1);
        dfs(root->right, dep+1);
    }
    int maxDepth(TreeNode *root) {
        ans = -1;
        if (root == NULL)
            return 0;
        dfs(root, 1);
        return ans;
    }
    int ans;
};
int main() {}
