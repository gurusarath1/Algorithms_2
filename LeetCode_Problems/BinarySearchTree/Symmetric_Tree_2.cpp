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
    bool isSymmetric(TreeNode* root) {
        
        return areMirrorTrees(root->left, root->right);
        
    }
    
    bool areMirrorTrees(TreeNode* tree1, TreeNode* tree2) {
        
        queue<TreeNode*> node_queue;
        
        node_queue.push(tree1);
        node_queue.push(tree2);
        
        TreeNode* node1;
        TreeNode* node2;
        
        while(!node_queue.empty()) {
            
            node1 = node_queue.front();
            node_queue.pop();
            
            node2 = node_queue.front();
            node_queue.pop();
            
            if(node1 == nullptr && node2 == nullptr) continue;
            if(node1 == nullptr || node2 == nullptr) return false;
            if(node1->val != node2->val) return false;
            
            if(node1 != nullptr) node_queue.push(node1->left);
            if(node2 != nullptr) node_queue.push(node2->right);
            
            if(node2 != nullptr) node_queue.push(node2->left);
            if(node1 != nullptr) node_queue.push(node1->right);
            
        }
        
        return true;
        
        
    }
};
