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
    int maxDepth(TreeNode* root) {
        
        return maxDepth_support(root, 0);
        
    }
    
    int maxDepth_support(TreeNode* root, int depth) {
        
        if(root == nullptr) {
            return depth;
        }
        
        int depth1 = maxDepth_support(root->left, depth+1);
        int depth2 = maxDepth_support(root->right, depth+1);
        
        if ( depth1 > depth2 ) {
            return depth1;
        } else {
            return depth2;
        }
   
    }
};
