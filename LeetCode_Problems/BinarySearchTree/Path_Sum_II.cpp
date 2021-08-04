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
    
    vector<vector<int>> result;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return result;
        
        pathSum_support(root, targetSum, 0, vector<int>());
        
        return result;
        
    }
    
    void pathSum_support(TreeNode* node, int targetSum, int currentSum, vector<int> current_path) {

        if(node == nullptr) {
            return;
        }
        
        if(targetSum == currentSum + node->val && node->left == nullptr && node->right == nullptr) {
            current_path.push_back(node->val);
            result.push_back(current_path);
            return;
        }
        
        current_path.push_back(node->val);
        
        pathSum_support(node->left, targetSum, currentSum + node->val, current_path);
        pathSum_support(node->right, targetSum, currentSum + node->val, current_path);
        
        return;
        
    }
    
};
