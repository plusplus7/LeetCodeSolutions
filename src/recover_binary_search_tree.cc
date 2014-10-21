class Solution {
public:
    void inorder(TreeNode *node) {
        if (node == NULL)
            return ;
        inorder(node->left);
        if (c != NULL && c->val > node->val) {
            if (a == NULL) {
                a = c;
                b = node;
            } else
                b = node;
        }
        c = node;
        inorder(node->right);
    }
    void recoverTree(TreeNode *root) {
        if (root == NULL)
            return ;
        a = NULL;
        b = NULL;
        c = NULL;
        inorder(root);
        if (a == NULL)
            return ;
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
    TreeNode *a, *b, *c;
};
