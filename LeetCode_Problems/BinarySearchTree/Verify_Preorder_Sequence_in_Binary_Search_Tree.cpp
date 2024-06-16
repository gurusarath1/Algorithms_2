class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {

        for(int sub_tree_root_index=0; sub_tree_root_index<preorder.size(); sub_tree_root_index++) {
            // Find the start index of the right subtree
            int right_subtree_start = sub_tree_root_index+1;
            // Right sub tree starts with the first value in the array that is greater than the current root value
            while(right_subtree_start < preorder.size() && preorder[right_subtree_start] < preorder[sub_tree_root_index] ) {
                right_subtree_start++;
            }

            // Check if all values in the right subtree are greater than the current root (preorder[sub_tree_root_index])
            for(int i=right_subtree_start; i<preorder.size(); i++) {
                if(preorder[i] < preorder[sub_tree_root_index]) return false;
            }

        }

        return true;
    }
};
