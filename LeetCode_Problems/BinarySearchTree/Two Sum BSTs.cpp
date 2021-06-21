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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        TreeNode* current_node = root1;
        stack<TreeNode*> node_stack;
        set<int> valuesInTree1;
        
        while(current_node != nullptr || !node_stack.empty()) {
            
            while(current_node != nullptr) {
                node_stack.push(current_node);
                current_node = current_node->left;
            }
            
            current_node = node_stack.top();
            node_stack.pop();
            valuesInTree1.insert(current_node->val);
            
            current_node = current_node->right;
            
        }
        
        current_node = root2;
        while(current_node != nullptr || !node_stack.empty()) {
            
            while(current_node != nullptr) {
                node_stack.push(current_node);
                current_node = current_node->left;
            }
            
            current_node = node_stack.top();
            node_stack.pop();
            if(valuesInTree1.find(target - current_node->val) != valuesInTree1.end()) {
                return true;
            }
            
            current_node = current_node->right;
            
        }
        
        return false;        
        
    }
};
