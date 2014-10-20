#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution{
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return ;
        if (root->left == NULL && root->right == NULL)
            return ;
        if (root->left != NULL && root->right != NULL)
            root->left->next = root->right;
        TreeLinkNode * find = root->next;
        while (find != NULL && find->left == NULL && find->right == NULL)
            find = find->next;
        if (find != NULL && root->right == NULL)
            root->left->next = find->left == NULL?find->right:find->left;
        else if (find != NULL && root->right != NULL)
            root->right->next = find->left == NULL?find->right:find->left;
        connect(root->right);
        connect(root->left);
    }
};
int main(){}
