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
    
    int num_leaves_deleted = 0;
    int num_leaves_deleted_in_prev_iteration = 0;
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(root == nullptr) return nullptr;
        
        do {
            
            num_leaves_deleted_in_prev_iteration = num_leaves_deleted;
            
            removeLeafNodes_support(root, target);
            
            num_leaves_deleted;
            
            // Continue deleting leaf nodes until no node is deleted
        } while(num_leaves_deleted > num_leaves_deleted_in_prev_iteration);
        
        
        // When root itself becomes a left
        // Delete the root
        if(root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        

        return root;
    }
    
    TreeNode* removeLeafNodes_support(TreeNode* root, int target) {
        
        if(root == nullptr) return nullptr;
        
        // Left leaf
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            if(root->left->val == target) {
                root->left = nullptr;
                num_leaves_deleted++;
                return root;
            }
        }
  
        // Right leaf
        if(root->right != nullptr && root->right->left == nullptr && root->right->right == nullptr) {
            if(root->right->val == target) {
                root->right = nullptr;
                num_leaves_deleted++;
                return root;
            }
        }
        
        // Not a leaf
        removeLeafNodes_support(root->left, target);
        removeLeafNodes_support(root->right, target);
        
        return root;
    }
};
