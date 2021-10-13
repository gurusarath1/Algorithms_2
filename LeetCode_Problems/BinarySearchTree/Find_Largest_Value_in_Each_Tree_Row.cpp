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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> result;
        queue<TreeNode*> q;
        
        if(root == nullptr) return result;
        
        q.push(root);
        
        while(!q.empty()) {
            
            int level_size = q.size();
            
            int maxVal = INT_MIN;
            for(int i=0; i<level_size; i++) {
                TreeNode* current_node = q.front();
                q.pop();
                
                if(maxVal < current_node->val) maxVal = current_node->val;
                
                if(current_node->left != nullptr) q.push(current_node->left);
                if(current_node->right != nullptr) q.push(current_node->right);
            }
            
            result.push_back(maxVal);
            
        }
        
        return result;
        
    }
};
