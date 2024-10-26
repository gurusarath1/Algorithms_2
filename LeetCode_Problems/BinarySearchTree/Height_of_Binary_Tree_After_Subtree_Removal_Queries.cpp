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

    int maxHeight = 0;
    map<int,int> max_height_after_removal;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        dfs_l_r(root, 0);
        maxHeight = 0;
        dfs_r_l(root, 0);
        
        vector<int> ret;
        for(int delete_node_num : queries) {
            ret.push_back(max_height_after_removal[delete_node_num]);
        }

        return ret;
    }

    void dfs_l_r(TreeNode* root, int current_height) {

        if(root == nullptr) {
            return;
        }

        max_height_after_removal[root->val] = maxHeight;

        maxHeight = max(maxHeight, current_height);

        dfs_l_r(root->left, current_height+1);
        dfs_l_r(root->right, current_height+1);

    }

    void dfs_r_l(TreeNode* root, int current_height) {

        if(root == nullptr) {
            return;
        }

        max_height_after_removal[root->val] = max(maxHeight, max_height_after_removal[root->val] );

        maxHeight = max(maxHeight, current_height);

        dfs_r_l(root->right, current_height+1);
        dfs_r_l(root->left, current_height+1);
    }
};
