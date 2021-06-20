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
    
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        
        reverse_inorder_traversal(root);
        
        return root;
        
    }
    
    void reverse_inorder_traversal(TreeNode* node) {
        
        if(node == nullptr) return;
        
        reverse_inorder_traversal(node->right);
        sum += node->val;
        node->val = sum;
        reverse_inorder_traversal(node->left);
        
    }
};
