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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        #define ROOT 1
        #define NOT_ROOT 0
         
        map<int, TreeNode*> memo;
        set<TreeNode*> roots;
        
        for(vector<int> desc : descriptions) {
            
            int parent = desc[0];
            int child = desc[1];
            int is_left = desc[2];
            TreeNode* parent_node = nullptr;
            TreeNode* child_node = nullptr;
            
            if(memo.find(parent) == memo.end()) {
                parent_node = new TreeNode(parent);
                memo[parent] = parent_node;
                //is_root[parent] = true;
                roots.insert(parent_node);
            } else {
                parent_node = memo[parent];           
            }
            
            if(memo.find(child) == memo.end()) {
                child_node = new TreeNode(child);
                memo[child] = child_node;
                //is_root[child] = false;
            } else {
                child_node = memo[child];
                //is_root[child] = false;
                roots.erase(child_node);
            }
                
            if(is_left) {
                parent_node->left = child_node;
            } else {
                parent_node->right = child_node;
            }
        }
        
        
        return *(roots.begin());
        
    }
};
