/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA = nullptr;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        LCA_support(root, p, q);
        
        return LCA;
        
    }
    
    
    int LCA_support(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int count = 0;
        
        if(root == nullptr) return 0;
        
        if(root->val == p->val) count++;
        else if(root->val == q->val) count++;
        
        count += LCA_support(root->left, p, q);
        
        if(count == 2 && LCA == nullptr) {
            LCA = root;
            return 2;
        }
        
        count += LCA_support(root->right, p, q);

        if(count == 2 && LCA == nullptr) {
            LCA = root;
            return 2;
        }        
        
        return count;
        
    }
    
    
    
};
