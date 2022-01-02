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

/*

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
and every node has no left child and only one right child.

*/

class Solution {
public:
    
    queue<TreeNode*> s;
    
    TreeNode* increasingBST(TreeNode* root) {
        recurse(root);
        
        TreeNode* current_node;
        TreeNode* prev_node;
        
        prev_node = s.front();
        root = s.front();
        s.pop();
        
        while(!s.empty()) {
            current_node = s.front();
            prev_node->right = current_node;
            prev_node->left =  nullptr;
            prev_node = current_node;
            s.pop();
        }
        
        prev_node->left = nullptr;
        prev_node->right = nullptr;
        
        return root;
    }
    
    void recurse(TreeNode* node) {
        
        if(node == nullptr) return;
        
        recurse(node->left);
        s.push(node);
        recurse(node->right);
        
    }
    
};
