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
    int minDiffInBST(TreeNode* root) {
        
        stack<TreeNode*> nodes_stack;
        
        TreeNode* current_node = root;
        
        int diff = 0;
        int current_val = 0;
        int min_diff = INT_MAX;
        bool first_node = true;
        
        while(current_node != nullptr || !nodes_stack.empty()) {
            
            while(current_node != nullptr) {
                nodes_stack.push(current_node);
                current_node = current_node->left;
            }
            
            current_node = nodes_stack.top();
            diff = abs(nodes_stack.top()->val - current_val);
            current_val = current_node->val;
            
            if(!first_node) {
                min_diff = min(diff, min_diff);
            } else {
                first_node = false;
            }
            
            nodes_stack.pop();
            
            current_node = current_node->right;
        }
        
        return min_diff;
        
    }
};
