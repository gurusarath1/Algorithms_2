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
    
    int max_sum = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        
        support_maxPathSum(root);
        
        return max_sum;
        
    }
    
    
    int support_maxPathSum(TreeNode* node) {
        
        if(node == nullptr) return 0;
        
        int left_path = support_maxPathSum(node->left);
        int right_path = support_maxPathSum(node->right);
        
        int path_sum_3 = left_path + right_path + node->val;
        int path_sum_2 = right_path + node->val;
        int path_sum_1 = left_path + node->val;
        
        
        if(path_sum_3 > max_sum) max_sum = path_sum_3;
        
        if(path_sum_2 > path_sum_1) {
            if(path_sum_2 > 0) return path_sum_2; else return 0;
        } else {
            if(path_sum_1 > 0) return path_sum_1; else return 0;
        }
        
    }
};
