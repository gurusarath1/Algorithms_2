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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        stack<TreeNode*> s;
        
        TreeNode* current_node = root;
        
        while(current_node != nullptr || !s.empty()) {
            
            if(current_node != nullptr) {
                
                s.push(current_node);
                current_node = current_node->left;
                
            } else {
                
                current_node = s.top();
                s.pop();
                
                result.push_back(current_node->val);
                
                current_node = current_node->right;
                
            }
            
        }
        
        return result;
    }
};
