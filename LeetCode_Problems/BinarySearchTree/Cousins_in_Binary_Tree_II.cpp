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
    TreeNode* replaceValueInTree(TreeNode* root) {

        vector<int> level_sums;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int level_size = q.size();
            int level_sum = 0;
            for(int i=0; i<level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level_sums.push_back(level_sum);
        }

        queue<pair<TreeNode*,TreeNode*>> qq;
        qq.push({root, nullptr});
        int level = 0;
        map<TreeNode*, int> update_map;
        while(!qq.empty()) {
            int level_size = qq.size();

            for(int i=0; i<level_size; i++) {
                TreeNode* node = qq.front().first;
                TreeNode* parent = qq.front().second;
                qq.pop();
                if(node->left) qq.push( {node->left, node} );
                if(node->right) qq.push( {node->right, node} );

                int left_val = 0, right_val = 0;
                if(parent && parent->left) left_val = parent->left->val;
                if(parent && parent->right) right_val = parent->right->val;

                if(parent == nullptr) left_val = node->val;

                update_map[node] = (level_sums[level] - left_val - right_val);
            }
            level++;
        }

        for(auto &n : update_map) {
            n.first->val = n.second;
        }

        return root;
    }
};
