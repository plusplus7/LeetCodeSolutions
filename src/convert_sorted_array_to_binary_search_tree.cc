#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode *build_tree(vector<int> &num, int &curr, int l, int r) {
        if (curr == num.size() || l > r)
            return NULL;
        if (l == r) {
            int val = num[curr];
            curr++;
            return new TreeNode(val);
        }
        TreeNode * node = new TreeNode(0);
        int mid = (l+r)>>1;
        node->left = build_tree(num, curr, l, mid-1);
        node->val = num[curr];
        curr++;
        node->right = build_tree(num, curr, mid+1, r);
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int cnt = num.size();
        if (cnt == 0) {
            return NULL;
        }
        int temp = 0;
        return build_tree(num, temp, 0, cnt-1);
    }
};
