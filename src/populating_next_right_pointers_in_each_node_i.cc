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
        if (root == NULL || root->left == NULL)
            return ;
        root->left->next = root->right;
        if (root->next != NULL)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};
int main(){}
