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
    
    int sum_nodes = 0;
    
    int findTilt(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        findTilt_support(root);
        
        sum_all_nodes(root);
        
        return sum_nodes;
        
    }
    
    void sum_all_nodes(TreeNode* root) {
        
        if(root == nullptr) return;
        sum_nodes += root->val;
        sum_all_nodes(root->left);
        sum_all_nodes(root->right);
        
    }
    
    int findTilt_support(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        int currentVal = root->val;
        
        int leftSum = findTilt_support(root->left);
        int rightSum = findTilt_support(root->right);
        
        int diff = leftSum - rightSum;
        
        diff = (diff > 0)? diff : -diff;
        
        root->val = diff;
        
        return leftSum + rightSum + currentVal;
        
    }
};
