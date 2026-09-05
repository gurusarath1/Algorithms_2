/*
Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

The left subtree values are less than the value of their parent (root) node's value.
The right subtree values are greater than the value of their parent (root) node's value.
Note: A subtree must include all of its descendants.
*/


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

    int max_nodes = 0;

    int largestBSTSubtree(TreeNode* root) {
        is_bst(root);
        return max_nodes;
    }

    class bst_params {
    public:
        bool valid;
        int num_nodes;
        int max_val;
        int min_val;
    };

    bst_params is_bst(TreeNode* node) {

        bst_params ret = {true, 0, INT_MIN, INT_MAX};

        if(node == nullptr) {
            return ret;
        }

        bool current_valid = true;
        int max_val = INT_MIN;
        int min_val = INT_MAX;

        bst_params ret_left = {true, 0, INT_MIN, INT_MAX};
        if(node->left != nullptr) {
            ret_left = is_bst(node->left);
            if(ret_left.max_val >= node->val) {
                current_valid = false;
            }
        }

        bst_params ret_right = {true, 0, INT_MIN, INT_MAX};
        if(node->right != nullptr) {
            ret_right = is_bst(node->right);
            if(ret_right.min_val < node->val) {
                current_valid = false;
            }
        }

        ret.valid = ret_left.valid && ret_right.valid && current_valid;
        int num_nodes = ret_left.num_nodes + ret_right.num_nodes + 1;
        ret.num_nodes = num_nodes;
        ret.max_val = max(node->val, max(ret_left.max_val, ret_right.max_val));
        ret.min_val = min(node->val, min(ret_left.min_val, ret_right.min_val));

        if(ret.valid && max_nodes < num_nodes) {
            max_nodes = num_nodes;
        }

        return ret;
    }

};
