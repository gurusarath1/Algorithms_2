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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        bool even_flag = false;
        int current_val;
        int prev;
        
        while(!q.empty()) {
            
            int level = q.size();
            
            for(int i=0; i<level; i++) {
                
                current_val = q.front()->val;

                if(q.front()->left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);
                
                q.pop();
                
                if(even_flag) {
                    if(current_val % 2 != 0) return false;
                } else {
                    if(current_val % 2 == 0) return false;
                }
                
                if(i == 0) {
                    prev = current_val;
                    continue;
                }
                
                if(even_flag) {
                    if(prev <= current_val) return false;
                } else {
                    if(prev >= current_val) return false;
                }
                
                prev = current_val;
                
            }
            
            if(even_flag) even_flag = false; else even_flag = true;
            
        }
        
        return true;
        
    }
};
