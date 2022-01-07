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
    
    priority_queue<int> pq;
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> result;
        
        recurse(root1);
        recurse(root2);
        
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        reverse(result.begin(),  result.end());
        
        return result;
    }
    
    void recurse(TreeNode* node) {
        
        if(node == nullptr) return;
        pq.push(node->val);
        
        recurse(node->left);
        recurse(node->right);
    }
};
