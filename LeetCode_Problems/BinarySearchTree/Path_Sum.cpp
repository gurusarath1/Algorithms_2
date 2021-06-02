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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return false;
        
        return support_hasPathSum(root, root->val, targetSum);
        
    }
    
    bool support_hasPathSum(TreeNode* root, int current_sum, int targetSum) {
        
        if(root->left == nullptr && root->right == nullptr) {
            if(current_sum == targetSum) {
                return true;
            } else {
                return false;
            }
        }
        
        bool left_tree_path_sum_flag = false;
        if(root->left != nullptr) {
            left_tree_path_sum_flag = support_hasPathSum(root->left, current_sum + root->left->val, targetSum);
        }
        
        if(left_tree_path_sum_flag) return true;
        
        bool right_tree_path_sum_flag = false;
        if(root->right != nullptr) {
            right_tree_path_sum_flag = support_hasPathSum(root->right, current_sum + root->right->val, targetSum);
        }
        
        return left_tree_path_sum_flag || right_tree_path_sum_flag;
        
        
    }
};
