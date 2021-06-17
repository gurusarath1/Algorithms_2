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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            
            cout << q.front()->val << "  \n";
            
            if( isSameTree(q.front(), subRoot) ) {
                return true;
            }
            
            
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            
            q.pop();
            
        }
        
        return false;
        
    }

    
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t1 == nullptr || t2 == nullptr) return false;
        
        if(t1->val != t2->val) return false;
        
        bool leftTree = isSameTree(t1->left, t2->left);
        if(!leftTree) return false;
        
        bool rightTree = isSameTree(t1->right, t2->right);
        if(!rightTree) return false;
        
        return true;    
        
    }
};
