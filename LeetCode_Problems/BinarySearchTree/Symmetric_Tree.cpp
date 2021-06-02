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
    bool isSymmetric(TreeNode* root) {
        
        return areMirrorTrees(root->left, root->right);
        
    }
    
    bool areMirrorTrees(TreeNode* tree1, TreeNode* tree2) {
        
        if(tree1 == nullptr && tree2 == nullptr) return true;
        if(tree1 == nullptr || tree2 == nullptr) return false;
        
        if( tree1->val == tree2->val && // Root nodes must be equal
            areMirrorTrees(tree1->left, tree2->right) && // left and right must be mirrors
            areMirrorTrees(tree1->right, tree2->left) // right and left must be mirrors
          ) {
            
            return true;
            
        } else {
            
            return false;
        
        }
        
    }
};
