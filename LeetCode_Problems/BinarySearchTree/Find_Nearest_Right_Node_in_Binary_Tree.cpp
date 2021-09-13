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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* current_node;
        bool next_is_nearest = false;
        
        while(!q.empty()) {
            
            int level = q.size();
            vector<TreeNode*> level_list(level, nullptr);
            
            for(int i=0 ; i<level; i++) {
                
                current_node = q.front();
                q.pop();
                
                if(next_is_nearest) return current_node;
                
                if(current_node->left != nullptr) q.push(current_node->left);
                if(current_node->right != nullptr) q.push(current_node->right);
                
                if(current_node == u) {
                    if(i == level - 1 && i != 0) {
                        return level_list[i-1];
                    } else {
                        next_is_nearest  = true;
                    }
                }

            }
            
            next_is_nearest = false;
        
        }
        
        return nullptr;
        
    }
};
