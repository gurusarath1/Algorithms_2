/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void get_tree_vals_from_serial(string &s, vector<TreeNode*> &return_tree_data) {

        stringstream ss(s); //convert my_string into string stream
        string node_str;

        while(getline(ss, node_str, ',')) { //use comma as delim for cutting string
            if(node_str != "NULL") {
                int val = stoi(node_str);
                return_tree_data.push_back(new TreeNode(val));
            }
            else return_tree_data.push_back(nullptr);
        }

        // Remove the last null nodes
        if(return_tree_data.size()) {
            while(return_tree_data[return_tree_data.size() - 1] == nullptr) {
                return_tree_data.pop_back();
            }
        }
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string tree_serial = "";

        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // if(not a null node)
            if(node) {
                q.push(node->left); // push both null and non-null nodes
                q.push(node->right); // push both null and non-null nodes

                tree_serial += to_string(node->val) + ",";
            } else {
                tree_serial += "NULL,";
            }
        }
        //cout << tree_serial <<endl;
        return tree_serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> level_order_nodes;
        get_tree_vals_from_serial(data, level_order_nodes);

        TreeNode* root = nullptr;
        // Check if we have atleast one node (root node)
        if(level_order_nodes.size()) root = level_order_nodes[0];

        if(root == nullptr) return nullptr;

        queue<TreeNode*> prev_nodes;
        prev_nodes.push(root); // start from root node
        int num_nodes_in_layer = prev_nodes.size(); // 1 (only root node)
        int current_idx = 1; // node after the root node in the array


        // Loop as long as there are nodes in the current layer of the BST
        while(num_nodes_in_layer) {

            // Connect the left and right nodes of the nodes in current layer
            for(int i=0; i<num_nodes_in_layer; i++) {

                // Current node for which we are connecting left and right trees
                TreeNode* current_node = prev_nodes.front();
                prev_nodes.pop();

                // Connect left sub-tree
                TreeNode* left_node = level_order_nodes[current_idx];
                current_node->left = left_node;
                if(left_node) prev_nodes.push(left_node); // Only add non-null nodes
                current_idx++;

                // Connect right sub-tree
                TreeNode* right_node = level_order_nodes[current_idx];
                current_node->right = right_node;
                if(right_node) prev_nodes.push(level_order_nodes[current_idx]); // Only add non-null nodes
                current_idx++;
            }

            num_nodes_in_layer = prev_nodes.size();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
