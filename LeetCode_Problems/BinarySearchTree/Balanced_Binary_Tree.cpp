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
    
    bool balanced = true;
    
    bool isBalanced(TreeNode* root) {
        
        heightOfTree(root);
        return balanced;
        
    }
    
    int heightOfTree(TreeNode* node) {
        
        if(node == nullptr) return -1;
        
        int left_height = heightOfTree(node->left);
        int right_height = heightOfTree(node->right);
        
        if(abs(left_height - right_height) > 1) balanced = false;
        
        return 1 + max(left_height , right_height);
    }
};
