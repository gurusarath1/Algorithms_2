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
    double maximumAverageSubtree(TreeNode* root) {
        
        return traverse(root)[2];
        
    }
    
    vector<double> traverse(TreeNode* node) {
        
        if(node == nullptr) {
            return vector<double>{0,0,0}; // { current sum includeing self,   num nodes including self,   maxAvg }
        }
        
        vector<double> leftSide = traverse(node->left);
        vector<double> rightSide = traverse(node->right);
        
        double sum = node->val + leftSide[0] + rightSide[0];
        double numNodes = leftSide[1] + rightSide[1] + 1;
        
        double max_avg = sum / numNodes;
        
        if(numNodes != 0) {
            max_avg = sum / numNodes;
        } else {
            max_avg = 0;
        }
        
        max_avg = max(max_avg, leftSide[2]);
        max_avg = max(max_avg, rightSide[2]);
        
        return vector<double>{sum, numNodes, max_avg};
        
        
    }
    
};
