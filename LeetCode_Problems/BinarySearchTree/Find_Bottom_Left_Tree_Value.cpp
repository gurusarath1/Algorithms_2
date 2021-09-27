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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        int first_val;
        
        q.push(root);
        
        while(!q.empty()) {
            
            int level_size = q.size();
            
            for(int i=0; i<level_size; i++) {
                TreeNode* current_node = q.front();
                q.pop();
                if(i == 0) first_val = current_node->val;
                if(current_node->left != nullptr) q.push(current_node->left);
                if(current_node->right != nullptr) q.push(current_node->right);
            }
            
        }
        
        return first_val;
    }
};
