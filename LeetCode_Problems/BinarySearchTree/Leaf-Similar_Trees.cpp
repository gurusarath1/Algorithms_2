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

    vector<int> leaves_1;
    vector<int> leaves_2;

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        get_leaves(root1, leaves_1);
        get_leaves(root2, leaves_2);

        if(leaves_1.size() != leaves_2.size()) return false;

        for(int i=0; i<leaves_1.size(); i++) {
            if(leaves_1[i] != leaves_2[i]) return false;
        }
        
        return true;
    }

    void get_leaves(TreeNode* root, vector<int> &leaves) {

        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
        }

        get_leaves(root->left, leaves);
        get_leaves(root->right, leaves);

    }

};
