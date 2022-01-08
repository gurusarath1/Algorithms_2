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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == nullptr) return nullptr;
        
        if(root->val == key) {
            
            if(root->left == nullptr && root->right == nullptr) {
                // Leaf Node
                return nullptr;
            } else if(root->left != nullptr && root->right == nullptr) {
                // Does not contain only right tree
                return root->left;
            } else if(root->left == nullptr && root->right != nullptr) {
                // Does not contain only left
                return root->right;
            } else {
                // Only contains right tree
                TreeNode* smallestNodeOnRightTree = smallestNode(root->right);
                root->right = deleteNode(root->right, smallestNodeOnRightTree->val);
                root->val = smallestNodeOnRightTree->val;
                return root;
            }
            
        } else {
            
            // Continue search
            if(key < root->val) {
                root->left = deleteNode(root->left, key);
            } else {
                root->right = deleteNode(root->right, key);
            }
            
        }
        
        return root;
        
    }
    
    TreeNode* smallestNode(TreeNode* root) {
        
        if(root == nullptr) return nullptr;
        
        // Smallest node is the left most node
        while(root->left != nullptr) {
            root = root->left;
        }
        
        return root;
    }
    
};
