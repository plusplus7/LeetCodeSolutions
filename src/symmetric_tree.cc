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
    bool gao(TreeNode *l, TreeNode *r) {
        
        if (l == NULL && r == NULL)
            return true;
        if (r != NULL && l != NULL) {
            if (l->val != r->val)
                return false;
            else
                return gao(l->left, r->right) && gao(l->right, r->left);
        }else {
            return false;
        }
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return gao(root->left, root->right);
    }
};
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(3);
    cout<<Solution().isSymmetric(root);
}
