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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        stack<TreeNode*> s;
        TreeNode* temp;
        map<TreeNode*, TreeNode*> parent;
        
        
        s.push(root);
        parent[root] = nullptr;
        int found_p_q_flag = 0;
        while(!s.empty()) {
            
            temp = s.top();
            s.pop();
            
            if(temp == p || temp == q) found_p_q_flag++;
            
            if(temp->left != nullptr) {
                s.push(temp->left);
                parent[temp->left] = temp;
            }
            
            if(temp->right != nullptr) {
                s.push(temp->right);
                parent[temp->right] = temp;
            }
            
            if(found_p_q_flag == 2) break;
        }
        
        
        set<TreeNode*> setX;
        
        TreeNode* node1 = p;
        TreeNode* node2 = q;
        
        while(node1 != nullptr || node2 != nullptr) {
            
            if(node1 != nullptr) {
                if(setX.find(node1) == setX.end()) {
                    setX.insert(node1);
                    node1 = parent[node1];
                } else {
                    return node1;
                }
            }
            
            if(node2 != nullptr) {
                if(setX.find(node2) == setX.end()) {
                    setX.insert(node2);
                    node2 = parent[node2];
                } else {
                    return node2;
                }
            }
            
        }
        
        
        
        return nullptr;
        
    }
    
};
