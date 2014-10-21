class Solution {
public:
    bool inorder(TreeNode *node) {
        if (node == NULL)
            return true;
        if (inorder(node->left) != true)
            return false;
        if (prev != NULL && prev->val >= node->val)
            return false;
        prev = node;
        if (inorder(node->right) != true)
            return false;
        return true;
    }
    bool isValidBST(TreeNode *root) {
        prev = NULL;
        return inorder(root);
    }
    TreeNode *prev;
};
