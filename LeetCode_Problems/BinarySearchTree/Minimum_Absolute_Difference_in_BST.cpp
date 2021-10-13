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
    
    priority_queue<int> q;
    
    int getMinimumDifference(TreeNode* root) {
        
        dfs(root);
        
        int min_dist = INT_MAX;
        
        int prev_val = q.top();
        q.pop();
        
        while(!q.empty()) {
            int current_val = q.top();
            q.pop();
            int dist = prev_val - current_val;
            
            if(dist < min_dist) min_dist = dist;
            prev_val = current_val;
        }
        
        return min_dist;
        
    }
    
    void dfs(TreeNode* root) {
        
        if(root == nullptr) return;
        
        q.push(root->val);
        
        if(root->left != nullptr) dfs(root->left);
        if(root->right != nullptr) dfs(root->right);
        
        return;
    }
};
