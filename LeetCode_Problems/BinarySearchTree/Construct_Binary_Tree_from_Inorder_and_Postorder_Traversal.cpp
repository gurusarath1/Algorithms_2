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
    
    int postOrderIndex;
    
    map<int, int> inorder_index;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        postOrderIndex = postorder.size() - 1;

        for(int i=0; i<inorder.size(); i++) {
            inorder_index[inorder[i]] = i;
        }
        
        return recurse(inorder, postorder, 0, inorder.size() - 1);
    }
    
    TreeNode* recurse(vector<int>& inorder, vector<int>& postorder, int start, int end) {
        
        if(start > end) return nullptr;
        
        int root = postorder[postOrderIndex];
        postOrderIndex--;
        
        TreeNode* root_node = new TreeNode(root);
            
        root_node->right = recurse(inorder, postorder, inorder_index[root] + 1, end);
        root_node->left = recurse(inorder, postorder, start, inorder_index[root] - 1);
        
        
        return root_node;
    }
};
