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
    
    int sum = 0;
    
    int sumNumbers(TreeNode* root) {
        
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        
        sumNumbers_support(root->left, root->val);
        sumNumbers_support(root->right, root->val);
        return sum;        
    }
    
    void sumNumbers_support(TreeNode* node, int currentNum) {
        
        if(node == nullptr) return;
        
        currentNum = currentNum * 10 + node->val;
        
        if(node->left == nullptr && node->right == nullptr) {
            sum += currentNum;
            return;
        }
        
        sumNumbers_support(node->left, currentNum);
        sumNumbers_support(node->right, currentNum);
        
    }
};
