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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long long> pq;

        queue<TreeNode*> q;
        q.push(root);

        int level = -1;
        while(!q.empty()) {
            long long level_sum = 0;
            int level_size = q.size();
            for(int i=0; i<level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                level_sum += node->val;
            }

            pq.push(level_sum);
            level++;
        }

        if(pq.size() < k) return -1;

        long long kth_largest_level_sum = 999;
        for(int i=0; i<k; i++) {
            kth_largest_level_sum = pq.top();
            pq.pop();
        }

        return kth_largest_level_sum;

    }
};
