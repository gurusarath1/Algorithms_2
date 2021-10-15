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
    
    int max_dia = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        traverse(root);
        
        return max_dia;
        
    }
    
    int traverse(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        int left = 0;
        int right = 0;
        
        left = 1 + traverse(root->left);
        right = 1 + traverse(root->right);
        
        if(max_dia < left + right - 2) {
            max_dia = left + right - 2;
        }
        
        return max(left, right);
        
    }
};
