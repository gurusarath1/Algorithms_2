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
    
    // Left less
    // Right Greater
    
    bool isValidBST(TreeNode* root) {
        
        if(root == nullptr) return true;
        
        stack<int> sortedVals;
        inOrderTraversal(root, sortedVals);
        
        int prev_val = sortedVals.top();
        sortedVals.pop();
        int stack_size = sortedVals.size();
        for(int i=0; i<stack_size; i++) {
            
            cout << prev_val << "  ";
            
            if(prev_val <= sortedVals.top()) {
                cout << "Invalid\n";
                return false;
            }
            
            prev_val = sortedVals.top();
            sortedVals.pop();
            
        }
        
        return true;
        
    }
    
    void inOrderTraversal(TreeNode* node, stack<int>& s) {
        
        if(node == nullptr) {
            return;
        }
        
        if(node->left == nullptr && node->right == nullptr) {
            s.push(node->val);
            cout << "Leaf: " << node->val << "   ";
            return;
        }
        
        
        inOrderTraversal(node->left, s);
        s.push(node->val);
        cout << "Non Leaf: " << node->val << "   ";
        inOrderTraversal(node->right, s);
        
    }
    
};
    
