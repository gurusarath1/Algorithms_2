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
    int countUnivalSubtrees(TreeNode* root) {
        
        int numUniVals = 0;
        isUniValue(root, numUniVals);
        
        return numUniVals;
        
    }
    
    bool isUniValue(TreeNode* root, int &numUniVals) {
        
        if(root == nullptr) return false;
        
        bool UniVal = false;
        bool left_UniVal = false;
        bool right_UniVal = false;
        
        if ( root->left != nullptr && root->right != nullptr ) {
            
            right_UniVal = isUniValue(root->right, numUniVals);
            left_UniVal = isUniValue(root->left, numUniVals);
            UniVal = (root->val == root->left->val) && (root->val == root->right->val) && right_UniVal && left_UniVal; 
            
        } else if ( root->right != nullptr ) {
            
            right_UniVal = isUniValue(root->right, numUniVals);
            UniVal = (root->val == root->right->val) && right_UniVal; 
            
        } else if ( root->left != nullptr ) {
            
            left_UniVal = isUniValue(root->left, numUniVals);
            UniVal = (root->val == root->left->val) && left_UniVal;
            
        } else {
            
            UniVal = true;
        }
        
        if(UniVal) {
            numUniVals++;
        }
        
        
        return UniVal;
        
    }
};
