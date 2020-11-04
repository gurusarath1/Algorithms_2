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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> vals;
        vector<vector<int>> returnList;
        int current_depth, prev_depth;
        TreeNode* temp;
        
        if(root == nullptr) return returnList;
        
        vals.push(make_pair(root, 0));
        prev_depth = -1;
        
        while(!vals.empty()) {
            
            temp = vals.front().first;
            current_depth = vals.front().second;
            vals.pop();
            
            if(temp->left != nullptr) vals.push(make_pair(temp->left, current_depth+1));
            if(temp->right != nullptr) vals.push(make_pair(temp->right, current_depth+1));
            
            if(prev_depth != current_depth) {
                
                vector<int> new_lst;
                new_lst.push_back(temp->val);
                returnList.push_back(new_lst);
                
            } else {
                
                returnList[current_depth].push_back(temp->val);
                
            }
            
            prev_depth = current_depth;   
        }
        
        return returnList;
        
    }
};
