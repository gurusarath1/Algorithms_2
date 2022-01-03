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
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build_max_tree_support(nums, 0, nums.size() - 1);
    }
    
    TreeNode* build_max_tree_support(vector<int>& nums, int start, int end) {
        
        if(start > end) return nullptr;
            
        int max_index = start;
        int max_val = nums[start];
        
        for(int i=start; i<=end; i++) {
            if(nums[i] > max_val) {
                max_val = nums[i];
                max_index = i;
            }
        }
        
        TreeNode* return_head = new TreeNode(max_val, nullptr, nullptr);
        
        return_head->left = build_max_tree_support(nums, start, max_index-1);
        return_head->right = build_max_tree_support(nums, max_index+1, end);
        
        return return_head;
        
    }
};
