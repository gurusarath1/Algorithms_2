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
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;

        q.push(root);
        int level_idx = 0;
        while(!q.empty()) {

            int level_size = q.size();

            vector<TreeNode*> level;
            for(int i=0; i<level_size; i++) {
                TreeNode* front_item = q.front();
                q.pop();
                if(level_idx & 1) level.push_back(front_item);
                if(front_item->left) q.push(front_item->left);
                if(front_item->right) q.push(front_item->right);
            }

            int i=0;
            int j=level_size - 1;

            if(level_idx & 1) { // only odd level index

                // reverse node values
                while(i < j) {
                    int temp = level[i]->val;
                    level[i]->val = level[j]->val;
                    level[j]->val = temp;
                    i++;
                    j--;
                }
            }

            level_idx++;
        }
        
        return root;
    }
};
