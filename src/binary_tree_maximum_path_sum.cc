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
    int ans;
    int dfs(TreeNode *node) {
        ans = max(node->val, ans);
        if (node->left == NULL && node->right == NULL) {
            return node->val;
        }
        int res = node->val;
        int l = 0;
        int r = 0;
        if (node->left != NULL) {
            l = dfs(node->left);
            res = max(res, l+node->val);
        }
        if (node->right != NULL) {
            r = dfs(node->right);
            res = max(res, r+node->val);
        }
        ans = max(ans, l+r+node->val);
        ans = max(res, ans);
        return res;
    }
    int maxPathSum(TreeNode *root) {
        if (root == NULL)
            return 0;
        ans = -0x7fffffff;
        dfs(root);
        return ans;
    }
};

int main() {
    TreeNode * head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);

    cout<<Solution().maxPathSum(head)<<endl;
}
