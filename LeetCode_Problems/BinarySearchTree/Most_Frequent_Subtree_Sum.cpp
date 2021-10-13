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
    
    map<int,int> sum_freq;
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        vector<int> result;
        
        dfs(root);
        
        
        int highest_freq = 0;
        for(pair<int,int> p : sum_freq) {
            if(p.second > highest_freq) {
                highest_freq = p.second;
            }
        }
        
        for(pair<int,int> p : sum_freq) {
            if(p.second == highest_freq) {
                result.push_back(p.first);
            }
        }
        
        return result;
    }
    
    int dfs(TreeNode* root) {
        
        if(root == nullptr) {
            return 0;
        }
        
        int sum = root->val + dfs(root->left) + dfs(root->right);
        
        sum_freq[sum] += 1;
        
        return sum;
        
    }
};
