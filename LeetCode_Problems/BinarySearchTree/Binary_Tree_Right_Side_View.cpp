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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> right_view_nodes;
        queue<TreeNode*> node_queue;
        
        if(root == nullptr) return right_view_nodes;
        
        node_queue.push(root);
        while(!node_queue.empty()) {
            
            int size_of_level = node_queue.size();
            
            for(int i=0; i<size_of_level; i++) {
                
                if(i == size_of_level-1) right_view_nodes.push_back(node_queue.front()->val);
                
                if(node_queue.front()->left) node_queue.push(node_queue.front()->left);
                if(node_queue.front()->right) node_queue.push(node_queue.front()->right);
                node_queue.pop();

            }
            
        }
        
        return right_view_nodes;
        
    }
};
