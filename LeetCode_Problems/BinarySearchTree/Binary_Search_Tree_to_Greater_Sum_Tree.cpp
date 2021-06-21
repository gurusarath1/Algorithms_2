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
    TreeNode* bstToGst(TreeNode* root) {
        
        TreeNode* current_node = root;
        
        stack<TreeNode*> node_stack;
        
        int sum = 0;
        
        while(current_node != nullptr || !node_stack.empty()) {
            
            while(current_node != nullptr) {
                node_stack.push(current_node);
                current_node = current_node->right;
            }
            
            current_node = node_stack.top();
            sum += current_node->val;
            current_node->val = sum;
            node_stack.pop();
            current_node = current_node->left;
            
        }
        
        return root;
        
        
    }
};
