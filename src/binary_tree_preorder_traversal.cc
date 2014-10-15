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
    void travel(TreeNode *root) {
        if (root == NULL)
            return ;
        m_vec.push_back(root->val);
        travel(root->left);
        travel(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root) {                  
        m_vec.clear();
        travel(root);
        return m_vec; 
    }
private:
    vector<int> m_vec;
};
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    vector<int> ans = Solution().preorderTraversal(root);
    for (int i=0; i<ans.size(); i++)
            cout<<ans[i]<<endl;
}
