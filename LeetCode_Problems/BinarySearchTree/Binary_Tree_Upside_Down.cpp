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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return upsidedown_tree(root, nullptr, nullptr);
    }

    TreeNode* upsidedown_tree(TreeNode* current_node, TreeNode* parent, TreeNode* parent_right) {

        if(current_node == nullptr) {
            return parent; // Leftmost leaf node is the new root node
        }

        // Keep moving left
        TreeNode* new_root = upsidedown_tree(current_node->left, current_node, current_node->right);

        // Check if we are back to the old root node
        if(parent != nullptr) {
            current_node->left = parent_right;
            current_node->right = parent;
        } else {
            // Old root node is now a leaf
            current_node->left = nullptr;
            current_node->right = nullptr;
        }

        return new_root; // New root is the leftmost leaf node
    }
};
