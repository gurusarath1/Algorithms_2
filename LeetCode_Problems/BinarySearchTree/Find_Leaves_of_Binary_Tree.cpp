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
    
    map<int,vector<int>> depth_nodes;
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> result;
        
        getDepth(root);
        
        for(pair<int,vector<int>> p : depth_nodes) {
            result.push_back(p.second);
        }
        
        return result;
        
    }
    
    int getDepth(TreeNode* node) {
        
        if(node == nullptr) {
            return 0;
        }
        
        int depth = 1 + max(getDepth(node->left), getDepth(node->right));
        
        depth_nodes[depth].push_back(node->val);
        
        return depth;
    }
};
