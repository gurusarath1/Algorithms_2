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

    int max_zig_zag;

    int longestZigZag(TreeNode* root) {

        longestZigZag_support(root, 0, 0);
        longestZigZag_support(root, 1, 0);

        return max_zig_zag;

    }

    void longestZigZag_support(TreeNode* root, int left, int path_len) {

        if(root == nullptr) {
            return;
        }

        max_zig_zag = max(max_zig_zag, path_len);

        if(left) {
            longestZigZag_support(root->left, 0, path_len+1);
            longestZigZag_support(root->right, 1, 1);
        } else {
            longestZigZag_support(root->right, 1, path_len+1);
            longestZigZag_support(root->left, 0, 1);
        }
        
    }
};
