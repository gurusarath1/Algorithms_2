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
    
    double smallest_delta = DBL_MAX;
    int closest_val;
    
    int closestValue(TreeNode* root, double target) {
        
        support_closestValue(root, target);
        
        return closest_val;
        
    }
    
    void support_closestValue(TreeNode* root, double target) {
        
        if(root == nullptr) return;
        
        double delta = root->val - target;
        if(delta < 0) delta = -delta;
        
        if(delta < smallest_delta) {
            smallest_delta = delta;
            closest_val = root->val;
        }
        
        support_closestValue(root->left, target);
        support_closestValue(root->right, target);
        
    }
};
