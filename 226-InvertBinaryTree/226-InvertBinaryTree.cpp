// Last updated: 6/26/2025, 7:57:46 PM
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)   
        {
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        return root;
        }
};