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
    
    vector<string> return_vector;
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(root == nullptr) {
            return return_vector;
        }
        
        support_binaryTreePaths(root, "");
        return return_vector;
    }
    
    void support_binaryTreePaths(TreeNode* root, string path_string) {
        
        int root_val = root->val;
        
        if(root->left == nullptr && root->right == nullptr) {
            if(path_string != "") path_string = path_string + "->" + to_string(root->val);
            else path_string = to_string(root->val);
            
            return_vector.push_back(path_string);
            return;
        }
        
        if(path_string != "") path_string = path_string + "->" + to_string(root->val);
        else path_string = to_string(root->val);
        
        if(root->left != nullptr) support_binaryTreePaths(root->left, path_string);
        if(root->right != nullptr) support_binaryTreePaths(root->right, path_string);
        
    }
    
};
