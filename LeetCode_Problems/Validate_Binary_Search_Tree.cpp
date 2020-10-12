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
    
    // Left less
    // Right Greater
    
    bool isValidBST(TreeNode* root) {
        
        int min = INT_MAX, max = INT_MIN;
        
        if(root == nullptr) {
            return true;
        }
        
        if(root->left == nullptr && root->right == nullptr) {
            cout << "Both NULL" ;
            return true;
        }
        
        
        findMax(root->left, max);
        findMin(root->right, min);
        
        cout << root->val << endl;
        cout << min << "  " << max << endl ;
        

        if(root->left == nullptr) {
            cout << "Left null";
            if(min > root->val) {
                return true && isValidBST(root->right);
            }
        }
        
        if(root->right == nullptr) {
            cout << "Right null";
            if(max < root->val) {
                return true && isValidBST(root->left);
            }
        }
        
        if(max < root->val && min > root->val) {
            return true && isValidBST(root->left) && isValidBST(root->right);
        } else {
            return false;
        }
        
        
    }
    
    void findMin(TreeNode* node, int& min) {
        
        if(node == nullptr) {
            return;
        }
        
        if(node->val < min) {
            min = node->val;
        }
        
        findMin(node->left, min);
        findMin(node->right, min);
        
    }
    
    void findMax(TreeNode* node, int& max) {
        
        if(node == nullptr) {
            return;
        }
        
        if(node->val > max) {
            max = node->val;
        }
        
        findMax(node->left, max);
        findMax(node->right, max);
        
    }
    
};
    
