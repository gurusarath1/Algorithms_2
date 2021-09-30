/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    enum visited_state {BOTH_PENDING, LEFT_DONE, BOTH_DONE};
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        stack<pair<TreeNode*, visited_state>> s;
        TreeNode* LCA = nullptr;
        
        
        s.push( pair{root, BOTH_PENDING} );
        int p_q_found = 0;
        
        while(!s.empty()) {
            
            if(s.top().first != LCA && (s.top().first == p || s.top().first == q) ) {
                
                p_q_found++;
                
                if(p_q_found == 2) return LCA;
                
                LCA = s.top().first;
            }
            
            if(s.top().second == BOTH_PENDING) {
                
                s.top().second = LEFT_DONE;
                if(s.top().first->left != nullptr) s.push( pair{s.top().first->left, BOTH_PENDING} );
                
            } else if(s.top().second == LEFT_DONE) {
                
                s.top().second = BOTH_DONE;
                if(s.top().first->right != nullptr) s.push( pair{s.top().first->right, BOTH_PENDING} );
                
            } else {
                
                if(s.top().first == LCA) {
                    s.pop();
                    LCA = s.top().first;
                } else {
                    s.pop();
                }
                
            }
            
        }
        
        
        
        return LCA;
        
    }
    
};
