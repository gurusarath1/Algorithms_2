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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        deque<TreeNode*> nodes_deque;
        TreeNode* temp_node;
        vector<vector<int>> ret_vector;
        
        if(root == nullptr) return ret_vector;
        
        nodes_deque.push_back(root);        
        bool direction = 0;
        
        while(!nodes_deque.empty()) {
            
            int current_level_size  = nodes_deque.size();
            vector<int> current_level_vector;
            
            for(int i=0; i<current_level_size; i++) {
                if(direction) {
                    temp_node = nodes_deque.front();
                    nodes_deque.pop_front();
                    current_level_vector.push_back(temp_node->val);
                    
                    if(temp_node->right != nullptr) nodes_deque.push_back(temp_node->right);
                    if(temp_node->left != nullptr) nodes_deque.push_back(temp_node->left);
                    
                } else {
                    temp_node = nodes_deque.back();
                    nodes_deque.pop_back();
                    current_level_vector.push_back(temp_node->val);
                    
                    if(temp_node->left != nullptr) nodes_deque.push_front(temp_node->left);  
                    if(temp_node->right != nullptr) nodes_deque.push_front(temp_node->right);
                                    
                }
            }
            
            ret_vector.push_back(current_level_vector);
            direction = !direction;
               
        }
        
        return ret_vector;
        
    }
};
