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
    
    vector<int> result;
    map<int,int> frequency_table;
    int highestFreq = 0;
    
    vector<int> findMode(TreeNode* root) {
        
        traverse(root);
        
        map<int,int>::iterator it = frequency_table.begin();
        
        
        while(it != frequency_table.end()) {
            if(it->second == highestFreq) {
                result.push_back(it->first);
            }
            
            it++;
        }
        
        return result;
    }
    
    void traverse(TreeNode* node) {
        
        if(node == nullptr) return;
        
        frequency_table[node->val] = frequency_table[node->val] + 1;
        
        if(highestFreq < frequency_table[node->val]) {
            highestFreq = frequency_table[node->val];
        }
        
        traverse(node->left);
        traverse(node->right);
        
    }
    
};
