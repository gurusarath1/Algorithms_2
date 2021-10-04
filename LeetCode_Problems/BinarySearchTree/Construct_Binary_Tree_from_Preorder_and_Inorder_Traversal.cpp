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
    
    int preOrderIndex = 0;
    
    map<int, int> inorder_index;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        for(int i=0; i<inorder.size(); i++) {
            inorder_index[inorder[i]] = i;
        }
        
        return recurse(preorder, inorder, 0, inorder.size() - 1);
        
        
    }
    
    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        
        if(start > end) return nullptr;
        
        int root = preorder[preOrderIndex];
        preOrderIndex++;
        
        TreeNode* root_node = new TreeNode(root);
            
        root_node->left = recurse(preorder, inorder, start, inorder_index[root] - 1);
        root_node->right = recurse(preorder, inorder, inorder_index[root] + 1, end);
        
        return root_node;
    }
};
