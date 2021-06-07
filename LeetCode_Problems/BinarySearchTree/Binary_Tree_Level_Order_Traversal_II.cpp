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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ret_vector;
        stack<vector<int>> ret_vec_stack;
        
        if(root == nullptr) return ret_vector;
        
        queue<TreeNode*> nodes_queue;
        
        nodes_queue.push(root);
        
        while(!nodes_queue.empty()) {
            
            int current_level_size = nodes_queue.size();
            vector<int> level_vec;
            
            //cout << current_level_size;
            
            for(int i = 0; i<current_level_size; i++) {
                
                level_vec.push_back(nodes_queue.front()->val);
                if(nodes_queue.front()->left != nullptr) nodes_queue.push(nodes_queue.front()->left);
                if(nodes_queue.front()->right != nullptr) nodes_queue.push(nodes_queue.front()->right);
                nodes_queue.pop();
                
            }
            
            ret_vec_stack.push(level_vec);
        }
        
        while(!ret_vec_stack.empty()) {
            ret_vector.push_back(ret_vec_stack.top());
            ret_vec_stack.pop();
        }
        
        return ret_vector;
        
    }
};
