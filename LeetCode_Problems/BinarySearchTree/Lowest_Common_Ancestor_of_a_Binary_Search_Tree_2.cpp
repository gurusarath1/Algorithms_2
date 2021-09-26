/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA = nullptr;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* current_node = root;
        
        while(current_node != nullptr) {
            
            // One of the value is equal to the current node value
            if(current_node->val == p->val || current_node->val == q->val) {
                return current_node; // LCA found
            }
            
            // Both p and q are in two different branches
            if(current_node->val > p->val && current_node->val < q->val) {
                return current_node; // LCA found
            }

            // Both p and q are in two different branches
            if(current_node->val < p->val && current_node->val > q->val) {
                return current_node; // LCA found
            }
            
            // p and q are in the left sub tree
            if(current_node->val > p->val && current_node->val > q->val) {
                current_node = current_node->left;
                continue;
            }
            
            // p and q are in the right sub tree
            if(current_node->val < p->val && current_node->val < q->val) {
                current_node = current_node->right;
                continue;
            }
            
        }
        
        
        return nullptr; // LCA not found
        
    }
};
