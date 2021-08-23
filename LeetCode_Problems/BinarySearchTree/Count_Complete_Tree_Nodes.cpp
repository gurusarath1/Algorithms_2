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
    int countNodes(TreeNode* root) {
        
        TreeNode* current_node;
        queue<TreeNode*> q;
        
        if(root == nullptr) return 0;
        
        q.push(root);
        int num_nodes = 0;
        while(!q.empty()) {
            
            current_node = q.front();
            q.pop();
            num_nodes++;
            
            if(current_node->left) q.push(current_node->left);
            if(current_node->right) q.push(current_node->right);
        }
        
        return num_nodes;
        
    }
};
