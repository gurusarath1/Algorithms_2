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
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        long long max_level_sum = INT_MIN;
        int max_level = 0;

        q.push(root);

        int current_level = 0;
        while(!q.empty()) {
            current_level++;
            int level_size = q.size();

            int level_sum = 0;
            for(int i=0; i<level_size; i++) {
                TreeNode* node = q.front();
                level_sum += node->val;
                q.pop();

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }

            if(max_level_sum < level_sum) {
                max_level_sum = level_sum;
                max_level = current_level;
            }

        }

        return max_level;
    }
};
