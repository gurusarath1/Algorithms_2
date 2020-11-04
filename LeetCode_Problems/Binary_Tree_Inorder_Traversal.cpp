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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> return_vals;
        
        stack<TreeNode*> nodeStack;
        TreeNode* currentNode;
        
        if(root == nullptr) {
            return return_vals;
        }
        
        // left, root, right
        currentNode = root;
        while(currentNode != nullptr || !nodeStack.empty()) {
            
            while(currentNode != nullptr) {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }
            
            currentNode = nodeStack.top();
            nodeStack.pop();
            return_vals.push_back(currentNode->val);
            currentNode = currentNode->right;
            
        }
        
        return return_vals;
        
    }
};
