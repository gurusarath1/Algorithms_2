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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return nullptr;
        }
        
        return sortedArrayToBST_support(nums, 0, nums.size()-1);
        
    }
    
    TreeNode* sortedArrayToBST_support(vector<int>& nums, int start_index, int end_index) {
        
        if(start_index > end_index) return nullptr;
        
        int mid_index = start_index + (end_index - start_index) / 2;
        
        TreeNode* root = new TreeNode(nums[mid_index]);
        
        root->right = sortedArrayToBST_support(nums, mid_index+1, end_index);
        root->left = sortedArrayToBST_support(nums, start_index, mid_index-1);
        
        return root;
        
    }
    
};
