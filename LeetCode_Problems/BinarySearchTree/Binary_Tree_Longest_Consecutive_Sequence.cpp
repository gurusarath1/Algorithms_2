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
    
    int maxPath = 0;
    
    int longestConsecutive(TreeNode* root) {
        
        int path_1 = support_longestConsecutive(root);
        
        if(path_1 > maxPath) maxPath = path_1;
        
        return maxPath;
        
    }
    
    int support_longestConsecutive(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        int root_val = root->val;
        
        int path_1 = support_longestConsecutive(root->left);
        int path_2 = support_longestConsecutive(root->right);
        
        if(path_1 > maxPath) maxPath = path_1;
        if(path_2 > maxPath) maxPath = path_2;
        
        if(path_1 > path_2) {
            if(root->left != nullptr && root->val == root->left->val - 1) return path_1 + 1;
            else return 1;
        } else if(path_1 < path_2) {
            if(root->right != nullptr && root->val == root->right->val - 1) return path_2 + 1;
            else return 1;
        } else {
            if(root->right != nullptr && root->val == root->right->val - 1) return path_2 + 1;
            else if(root->left != nullptr && root->val == root->left->val - 1) return path_1 + 1;
            else return 1;
        }
        
    }
};
