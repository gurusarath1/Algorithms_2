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
    vector<vector<int>> verticalOrder(TreeNode* root) {

        vector<vector<int>> result;
        int max_left = 0;
        int max_right = 0;

        if(root == nullptr) return result;

        get_array_length(root, 0, 0, max_left, max_right); 
        result.resize(max_left + max_right + 1);

        fill_vertical_order_array(root, result, 0, max_left);

        return result;
    }

    void get_array_length(TreeNode* root, int left_idx, int right_idx, int &max_left_idx, int &max_right_idx) {
        if(root == nullptr) return;
        if(left_idx > max_left_idx) max_left_idx = left_idx;
        if(right_idx > max_right_idx) max_right_idx = right_idx;
        get_array_length(root->left, left_idx+1, right_idx-1, max_left_idx, max_right_idx);
        get_array_length(root->right, left_idx-1, right_idx+1, max_left_idx, max_right_idx);
    }

    void fill_vertical_order_array(TreeNode* root_node, vector<vector<int>> &result, int offset_from_root_index, int root_index) {

        queue<pair<TreeNode*,int>> q;
        q.push({root_node, root_index});

        while(!q.empty()) {

            pair<TreeNode*,int> node_idx_pair = q.front();
            q.pop();

            TreeNode* current_node = node_idx_pair.first;
            int idx = node_idx_pair.second;

            if(current_node) {
                result[idx].push_back(current_node->val);

                if(current_node->left) q.push({current_node->left, idx - 1});
                if(current_node->right) q.push({current_node->right, idx + 1});
            }

        }

    }
};
