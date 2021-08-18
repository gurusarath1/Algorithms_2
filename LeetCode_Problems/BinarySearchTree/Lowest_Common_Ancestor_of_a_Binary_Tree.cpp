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
        
        lowestCommonAncestor_support(root, p, q);
        
        return LCA;
        
    }
    
    int lowestCommonAncestor_support(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int counts = 0;
        if(root == nullptr) return 0;
        
        if(root->val == p->val) counts += 1;
        if(root->val == q->val) counts += 1;
        
        counts += lowestCommonAncestor_support(root->right, p, q);
        counts += lowestCommonAncestor_support(root->left, p, q);
        
        
        
        if(counts == 2 && LCA == nullptr) {
            LCA = root;
        }
        
        return counts;
        
        
    }
    
};
