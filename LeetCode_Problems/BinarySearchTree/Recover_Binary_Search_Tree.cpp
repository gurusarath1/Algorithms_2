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
    void recoverTree(TreeNode* root) {
        
        TreeNode* current_node = root;
        TreeNode* prev_node = nullptr;
        stack<TreeNode*> s;
        
        TreeNode* node_1;
        TreeNode* node_2;
        int prev_val = INT_MIN;
        bool node_1_found = false;
        bool node_2_found = false;
        
        while(!s.empty() || current_node != nullptr) {
            
            if(current_node != nullptr) {
                s.push(current_node);
                current_node = current_node->left;
            } else {
                
                current_node = s.top();
                s.pop();
                
                if(current_node->val < prev_val && !node_1_found) {
                    node_1_found = true;
                    prev_val = INT_MIN; 
                    node_1 = prev_node;
                    break;
                }
                
                prev_node = current_node;
                prev_val = prev_node->val;
                current_node = current_node->right;
                
            }
            
        }
        
        current_node = root;
        prev_val = INT_MAX;
        while(!s.empty() || current_node != nullptr) {
            
            if(current_node != nullptr) {
                s.push(current_node);
                current_node = current_node->right;
            } else {
                
                current_node = s.top();
                s.pop();
                
                if(current_node->val > prev_val && !node_2_found) {
                    node_2_found = true;
                    prev_val = INT_MIN; 
                    node_2 = prev_node;
                    continue;
                }
                
                prev_node = current_node;
                prev_val = prev_node->val;
                current_node = current_node->left;
                
            }
            
        }
        
        
        if(node_1_found && node_2_found) {
            int temp = node_1->val;
            node_1->val = node_2->val;
            node_2->val = temp;
        }
        
        return;
        
    }
};
