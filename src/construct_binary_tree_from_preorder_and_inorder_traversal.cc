#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *build_tree(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (il == ir)
            return new TreeNode(inorder[il]);
        if (il > ir || ir >= inorder.size() || il >= inorder.size()
                    || pr >= preorder.size() || pl >= preorder.size())
            return NULL;
        TreeNode *node = new TreeNode(preorder[pl]);
        int tmp = 0, cnt = 0;
        for (tmp=il; tmp<=ir; tmp++) {
            if (preorder[pl] == inorder[tmp])
                break;
        }
        cnt = tmp-il;
        node->left = build_tree(preorder, pl+1, pl+cnt, inorder, il, tmp-1);
        node->right = build_tree(preorder, pl+cnt+1, pr, inorder, tmp+1, ir);
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int p_len = preorder.size()-1;
        int i_len = inorder.size()-1;
        return build_tree(preorder, 0, p_len, inorder, 0, i_len);
    }
};
//DBACEGF ABCDEFG 
//BCAD CBAD
void inorder(TreeNode *head){
    if (head== NULL)
        return ;
    inorder(head->left);
    cout<<head->val<<" ";
    inorder(head->right);

}
int main() {
    const int len = 4;
    int a[len] = {
    //4, 2, 1, 3, 5, 7, 6
    2,3,1,4
    };
    int b[len] = {
    //1, 2, 3, 4, 5, 6, 7
    3,2,1,4
    };
    vector<int> va(a, a+len);
    vector<int> vb(b, b+len);
    TreeNode *ans = Solution().buildTree(va, vb);
    inorder(ans);
    cout<<endl;
}
