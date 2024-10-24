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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        return support_flipEquiv(root1, root2);
    }

    bool support_flipEquiv(TreeNode* root1, TreeNode* root2) {

        if(root1 && root2 && root1->val != root2->val) { // unequal root values
            return false;
        } else if(root1 == nullptr && root2 == nullptr) { // Both are null is okay
            return true;
        } else if(root1 == nullptr) { // one is null is not okay
            return false;
        } else if(root2 == nullptr) {  // one is null is not okay
            return false;
        } else { // Both roots are valid (non null). Let's test the subtrees

            if(root1->left && root1->right && root2->left && root2->right) { // Both have left and right subtrees are non null case

                if(root1->left->val == root1->right->val == root2->left->val == root2->right->val) { // Equal left and right values

                    // May or may not be swapped
                    bool no_swap_case = support_flipEquiv(root1->left, root2->left) && support_flipEquiv(root1->right, root2->right);
                    if(no_swap_case) return true;

                    bool swap_case = support_flipEquiv(root1->right, root2->left) && support_flipEquiv(root1->left, root2->right);
                    if(swap_case) return true;

                    return false;

                } else {
                    if( (root1->left->val == root2->left->val) && (root1->right->val == root2->right->val) ) { // No swap left == left and right == right

                        bool no_swap_case = support_flipEquiv(root1->left, root2->left) && support_flipEquiv(root1->right, root2->right);
                        if(no_swap_case) return true;

                        return false;

                    } else if((root1->left->val == root2->right->val) && (root1->right->val == root2->left->val)) { // swap left == right and right == left
                        bool swap_case = support_flipEquiv(root1->right, root2->left) && support_flipEquiv(root1->left, root2->right);
                        if(swap_case) return true;

                        return false;
                    }
                }
            } else {

                if(root1->left == nullptr && root2->left == nullptr && root1->right == nullptr && root2->right == nullptr) { // Leaf node
                    return true;
                }

                if(root1->left == nullptr && root1->right == nullptr) { // only roo1 is a left node
                    return false;
                }

                if(root2->left == nullptr && root2->right == nullptr) { // only root2 is a left node
                    return false;
                }

                if(root1->left == nullptr && root2->left == nullptr && (root1->right->val == root2->right->val) ) { // left null both have rights
                        bool no_swap_case = support_flipEquiv(root1->right, root2->right);
                        if(no_swap_case) return true;

                        return false;
                }

                if(root1->right == nullptr && root2->right == nullptr && (root1->left->val == root2->left->val) ) { // right null both have lefts
                        bool no_swap_case = support_flipEquiv(root1->left, root2->left);
                        if(no_swap_case) return true;

                        return false;
                }

                if(root1->right == nullptr && root2->left == nullptr && (root1->left->val == root2->right->val) ) {
                        bool swap_case = support_flipEquiv(root1->left, root2->right);
                        if(swap_case) return true;

                        return false;
                }

                if(root1->left == nullptr && root2->right == nullptr && (root1->right->val == root2->left->val) ) {
                        bool swap_case = support_flipEquiv(root1->right, root2->left);
                        if(swap_case) return true;

                        return false;
                }
            }

        }    

        return false;
    }

};
