// Last updated: 6/26/2025, 7:58:22 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        vector<int>left=postorderTraversal(root->left);
        ans.insert(ans.end(),left.begin(),left.end());
        vector<int>right=postorderTraversal(root->right);
        ans.insert(ans.end(),right.begin(),right.end());
        ans.push_back(root->val);
        return ans;
    }
};