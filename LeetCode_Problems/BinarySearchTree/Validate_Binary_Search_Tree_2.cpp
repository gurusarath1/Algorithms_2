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
    bool isValidBST(TreeNode* root) {
        return isValidBST_support(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool isValidBST_support(TreeNode* root, long long lowerLimit, long long upperLimit) {
        
        if(root == nullptr) return true;
        
        if(root->val <= lowerLimit || root->val >= upperLimit) return false;
        
        /*
        When you go left - upper limit changes
        When you go right - lower limit changes
        */
        
        return isValidBST_support(root->left, lowerLimit, root->val) && isValidBST_support(root->right, root->val, upperLimit);
        
    }
};
