#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode *build_tree(ListNode *&curr, int l, int r) {
        if (curr == NULL || l > r)
            return NULL;
        if (l == r) {
            int val = curr->val;
            curr = curr->next;
            return new TreeNode(val);
        }
        TreeNode * node = new TreeNode(0);
        int mid = (l+r)>>1;
        node->left = build_tree(curr, l, mid-1);
        node->val = curr->val;
        curr = curr->next;
        node->right = build_tree(curr, mid+1, r);
        return node;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        int cnt = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        temp = head;
        return build_tree(temp, 0, cnt-1);
    }
};
