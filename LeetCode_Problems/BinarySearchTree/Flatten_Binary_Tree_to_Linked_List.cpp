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
    
    void flatten(TreeNode* root) {
        
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        
        
        if(root->left == nullptr) {
            
        } else {
            flatten(root->left);
        }
        
        flatten(root->right);
        
        TreeNode* left_flat = root->left;
        TreeNode* right_flat = root->right;
        TreeNode* left_flat_right_end = root->left;
        
        while(left_flat_right_end != nullptr && left_flat_right_end->right != nullptr) 
            left_flat_right_end = left_flat_right_end->right;
        
        
        if(left_flat != nullptr) {
            left_flat_right_end->right = root->right;
            root->right = left_flat;
            root->left = nullptr;
        }
        
        cout << "";
        
        return;
        
    }
};
