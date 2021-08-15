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
    
    int good_nodes = 0;
    
    int goodNodes(TreeNode* root) {
        
        goodNodes_support(root, INT_MIN);
        
        return good_nodes;
        
    }
    
    void goodNodes_support(TreeNode* node, int greatest) {
        
        if(node == nullptr) return;
        
        if(greatest <= node->val) {
            good_nodes++;
            greatest = node->val;
        }
        
        goodNodes_support(node->left, greatest);
        goodNodes_support(node->right, greatest);
        
        return;
    }
};
