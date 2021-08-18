/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        stack<TreeNode*> s;
        TreeNode* currentNode = root;
        bool nextIsSuccessor = false;
        
        while(currentNode != nullptr || !s.empty()) {
            
            if(currentNode != nullptr) {
                s.push(currentNode);
                currentNode = currentNode->left;
            } else {
                
                currentNode = s.top();
                s.pop();
                
                if(nextIsSuccessor) {
                    return currentNode;
                } else if(p == currentNode) {
                    nextIsSuccessor = true;
                }
                
                currentNode = currentNode->right;
            }
            
        }
        
        return nullptr;
        
    }
};
