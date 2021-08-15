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
        
        if(root == nullptr) return true;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            
            TreeNode* current_node = q.front();
            q.pop();
            
            if(!allLess(current_node->left, current_node->val)) return false;
            if(!allGreater(current_node->right, current_node->val)) return false;
            
            if(current_node->left != nullptr) q.push(current_node->left);
            if(current_node->right != nullptr) q.push(current_node->right);
            
        }
        
        return true;
        
    }
    
    bool allLess(TreeNode* root, int val) {
        
        if(root == nullptr) return true;
        
        if(val <= root->val) return false;
        
        return allLess(root->left, val) && allLess(root->right, val);
        
    }
    
    bool allGreater(TreeNode* root, int val) {
        
        if(root == nullptr) return true;
        
        if(val >= root->val) return false;
        
        return allGreater(root->left, val) && allGreater(root->right, val);
        
    }
    
    
};
