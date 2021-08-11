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
    
    
    int count;
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return 0;
        
        map<int,int> prefixSumTrack;
        prefixSumTrack[0] = 1;
        count = 0;
        
        traverse(root, targetSum, 0, prefixSumTrack);
        
        return count;
        
    }
    
    void traverse(TreeNode* root, int targetSum, int prefixSum, map<int,int> prefixSumTrack) {
        
        if(root == nullptr) return;
        
        prefixSum += root->val;
        
        if(prefixSumTrack.find(prefixSum - targetSum) != prefixSumTrack.end()) {
            count += prefixSumTrack[prefixSum - targetSum];
        }
        
        prefixSumTrack[prefixSum] = prefixSumTrack[prefixSum] + 1; 
        
        traverse(root->left, targetSum, prefixSum, prefixSumTrack);
        traverse(root->right, targetSum, prefixSum, prefixSumTrack);
    }
    
};
