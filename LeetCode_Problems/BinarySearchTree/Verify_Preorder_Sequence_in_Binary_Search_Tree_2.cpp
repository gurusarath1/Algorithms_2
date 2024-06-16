class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {

        int i = 0;
        return verifyPreorder_support(i, preorder, INT_MIN, INT_MAX);
    }

    bool verifyPreorder_support(int &current_idx, vector<int>& preorder, int min_value, int max_value) {

        if(current_idx >= preorder.size()) {
            return true;
        }

        int sub_tree_root_val = preorder[current_idx];
    
        if(sub_tree_root_val <= min_value || sub_tree_root_val >= max_value) {
            return false;
        }

        current_idx++;
        bool is_valid_left = verifyPreorder_support(current_idx, preorder,  min_value, sub_tree_root_val);
        bool is_valid_right = verifyPreorder_support(current_idx, preorder,  sub_tree_root_val, max_value);

        return is_valid_left || is_valid_right;
    }

};
