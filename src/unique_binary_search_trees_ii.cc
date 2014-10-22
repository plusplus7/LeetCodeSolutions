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
    vector<TreeNode *> generateTrees(int l, int r) {
        vector<TreeNode *> ans;
        ans.clear();
        if (l > r)
            return ans;
        if (l == r) {
            ans.push_back(new TreeNode(l));
            return ans;
        }
        for (int i=l; i<=r; i++) {
            vector<TreeNode *> lv = generateTrees(l,i-1);
            vector<TreeNode *> rv = generateTrees(i+1,r);
            if (lv.size() == 0) {
                for (auto irv : rv) {
                    TreeNode *node = new TreeNode(i);
                    node->left = NULL;
                    node->right = irv;
                    ans.push_back(node);
                }
            }
            if (rv.size() == 0) {
                for (auto ilv : lv) {
                    TreeNode *node = new TreeNode(i);
                    node->right = NULL;
                    node->left = ilv;
                    ans.push_back(node);
                }
            }
            for (auto ilv : lv) {
                for (auto irv : rv) {
                    TreeNode *node = new TreeNode(i);
                    node->left = ilv;
                    node->right = irv;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode *> ans;
            ans.clear();
            ans.push_back(NULL);
            return ans;
        }    
        return generateTrees(1,n);
    }
};

int main() {
    vector<TreeNode *> ans = Solution().generateTrees(3);
    cout<<ans.size()<<endl;
}
