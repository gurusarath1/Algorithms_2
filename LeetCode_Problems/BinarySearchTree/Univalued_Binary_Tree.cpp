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
    bool isUnivalTree(TreeNode* root) {
        
        if(root == nullptr) return false;
        
        int val = root->val;
        
        return isUnivalTree_support(root, val);
        
    }
    
    bool isUnivalTree_support(TreeNode* root, int val) {
        if(root == nullptr) return true;
        
        if(root->val != val) return false;
        
        return isUnivalTree_support(root->left, val) && isUnivalTree_support(root->right, val);
    }
};
