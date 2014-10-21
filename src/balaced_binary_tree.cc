#include <iostream>
using namespace std;
class Solution {
public:
    int dfs(TreeNode *node) {
        if (node == NULL)
            return 0;
        return max(dfs(node->left, dep+1), dfs(node->right, dep+1))+1;
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        if (abs(dfs(node->left)-dfs(node->right)) > 1)
            return false;
        else
            return isBalanced(root->left) == true && isBalanced(root->right) == true;
    }
};
