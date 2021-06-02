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
    int maxDepth(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        TreeNode* node = root;
        
        queue<TreeNode*> nodes_queue;
        
        nodes_queue.push(node);
        int depth = 0;
        while(!nodes_queue.empty()) {
            
            depth++;
            
          // Get the size of the current level
            int level_size = nodes_queue.size();
            
          // iterate a single level
            for(int i = 0; i < level_size; i++) {
                
                node = nodes_queue.front();
                nodes_queue.pop();
                
                if(node->left) nodes_queue.push(node->left);
                if(node->right) nodes_queue.push(node->right);
                
            }
            
        }
        
        return depth;
        
    }
};
