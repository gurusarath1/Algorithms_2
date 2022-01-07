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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> result;
        
        if(root == nullptr) return result;
        
        s1.push(root);
        
        while(!s1.empty()) {
            
            TreeNode* current_node = s1.top();
            s1.pop();
            s2.push(current_node);
            
            if(current_node->left) s1.push(current_node->left);
            if(current_node->right) s1.push(current_node->right);   
        }
        
        while(!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        
        return result;
    }
};
