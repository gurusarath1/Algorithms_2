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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> list;
        
        createLevelOrderVector(root, 0, list);
        
        return list;
        
    }
    
    void createLevelOrderVector(TreeNode* node, int level, vector<vector<int>>& list) {
        
        if(node == nullptr) {
            return;
        }
        
        if(list.size() < level+1) {
            vector<int> a;
            a.push_back(node->val);
            list.push_back(a);
        } else {
            list[level].push_back(node->val);
        }
        
        createLevelOrderVector(node->left, level+1, list);
        createLevelOrderVector(node->right, level+1, list);
    }
    
};
