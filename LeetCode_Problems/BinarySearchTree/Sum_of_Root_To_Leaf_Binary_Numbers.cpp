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
    int sum = 0;
    
    int sumRootToLeaf(TreeNode* root) {
        
        vector<int> bits;
        recurse(root, 0, bits);
        
        return sum;
        
    }
    
    void recurse(TreeNode* node, int depth, vector<int>& bits) {
        
        if(node == nullptr) return;
        
        if(node->left == nullptr && node->right == nullptr) {
            
            bits.push_back(node->val);
            
            int current_sum = 0;
            int j = 1;
            for(int i = bits.size() - 1; i >= 0; i--) {
                current_sum += bits[i] * j;
                j = j*2;
            }
            
            sum += current_sum;
            
            bits.pop_back();
            return;
        }
        
        bits.push_back(node->val);
        
        recurse(node->left, depth+1, bits);
        recurse(node->right, depth+1, bits);
        
        bits.pop_back();
        
    }
};
