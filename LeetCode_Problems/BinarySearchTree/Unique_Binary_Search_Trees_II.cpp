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
    vector<TreeNode*> generateTrees(int n) {

        if(n == 0) return vector<TreeNode*>();

        map<vector<int>, vector<TreeNode*>> memo;
        return generate_trees_array(1, n, memo);
    }

    vector<TreeNode*> generate_trees_array(int start_node_val, int end_node_val, map<vector<int>, vector<TreeNode*>>&memo) {

        vector<TreeNode*> all_trees;

        // End node
        if(start_node_val > end_node_val) {
            all_trees.push_back(nullptr);
        }

        // Check memo
        vector<int> start_end;
        start_end.push_back(start_node_val);
        start_end.push_back(end_node_val);
        if(memo.find(start_end) != memo.end()) {
            return memo[start_end];
        }

        // Set root node from start to end
        for(int root_node_val=start_node_val; root_node_val <= end_node_val; root_node_val++) {

            // Generate all possible left trees
            vector<TreeNode*> left_trees = generate_trees_array(start_node_val, root_node_val-1, memo);
            // Generate all possible right trees
            vector<TreeNode*> right_trees = generate_trees_array(root_node_val+1, end_node_val, memo);

            // Generate all combinations using the left and right trees
            for(TreeNode* left_tree : left_trees) {
                for(TreeNode* right_tree : right_trees) {
                    
                    // Create the tree
                    TreeNode* root_node = new TreeNode(root_node_val);
                    root_node->left = left_tree;
                    root_node->right = right_tree;

                    // Add tree to result
                    all_trees.push_back(root_node);
                }
            }

        }

        // Memorize this start and end pair trees
        memo[start_end] = all_trees;

        return all_trees;
    }
};
