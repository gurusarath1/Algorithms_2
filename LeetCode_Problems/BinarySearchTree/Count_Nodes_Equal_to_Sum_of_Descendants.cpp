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
    
    int num_nodes = 0;
    
    int equalToDescendants(TreeNode* root) {
        
        support_equalToDescendants(root);
        
        return num_nodes;
        
    }
    
    int support_equalToDescendants(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        long long sum_1 = support_equalToDescendants(root->left);
        long long sum_2 = support_equalToDescendants(root->right);
        
        if(sum_1 + sum_2 == root->val) {
            num_nodes += 1;
        }
        
        return sum_1 + sum_2 + root->val;
        
    }
    
};
