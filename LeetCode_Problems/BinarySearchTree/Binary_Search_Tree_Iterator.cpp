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
class BSTIterator {
public:
    
    int index = 0;
    vector<int> ary;
    
    BSTIterator(TreeNode* root) {
        createArray(root);
    }
    
    void createArray(TreeNode* root) {
        if(root == nullptr) return;
        createArray(root->left);
        ary.push_back(root->val);
        createArray(root->right);
        return;
    }
    
    int next() {
        int val = ary[index];
        index++;
        
        return val;
    }
    
    bool hasNext() {
        return index <= ary.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
