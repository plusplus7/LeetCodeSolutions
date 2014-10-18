#include <iostream>

class Solution {
public:
    void dfs(int &ans, int cur, TreeNode *node) {
        if (node->left == NULL && node->right == NULL) {
            ans = ans+cur;
        } else if (node->left != NULL && node->right != NULL) {
            dfs(ans, cur*10+node->left->val, node->left);
            dfs(ans, cur*10+node->right->val, node->right);
        } else if (node->left != NULL && node->right == NULL) {
            dfs(ans, cur*10+node->left->val, node->left);
        } else if (node->left == NULL && node->right != NULL) {
            dfs(ans, cur*10+node->right->val, node->right);
        }
    }
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
        int ans = 0;
        dfs(ans, root->val, root);
        return ans;
    }
};
int main() {
}
