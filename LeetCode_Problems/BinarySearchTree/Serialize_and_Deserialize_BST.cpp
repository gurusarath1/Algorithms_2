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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        vector<int> pre_order;
        dfs(root, pre_order);

        string pre_order_enc = "";
        for(int n : pre_order) {
            pre_order_enc += to_string(n) + ",";
        }

        return pre_order_enc;
    }

    void dfs(TreeNode* node, vector<int> &pre_order) {
        if(node == nullptr) {
            return;
        }

        pre_order.push_back(node->val);

        dfs(node->left, pre_order);
        dfs(node->right, pre_order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data == "") return nullptr;

        istringstream strmX(data);
        string tok;
        
        vector<int> pre_order;
        while(getline(strmX, tok, ','))
        {
            pre_order.push_back(stoi(tok));
        }

        // Create the root and start recursion
        TreeNode* root = new TreeNode(pre_order[0]);
        buildTree(root, pre_order, 1, pre_order.size() - 1);

        return root;
    }

    // start and end index of pre_order
    void buildTree(TreeNode* root, vector<int> &pre_order, int start, int end) {

        if(root == nullptr) return;
        if(start > end) return;

        int current_val = root->val;

        // Search for right subtree
        int right_tree_start;
        for(right_tree_start=start; right_tree_start<=end; right_tree_start++) {
            if(pre_order[right_tree_start] > current_val) {
                break;
            }
        }

        // Create right sub tree
        if(right_tree_start <= end) {
            root->right = new TreeNode(pre_order[right_tree_start]);
            buildTree(root->right, pre_order, right_tree_start+1, end);
        } else {
            root->right = nullptr; // No right tree
        }

        // Create left sub tree
        if(right_tree_start == start) {
            root->left = nullptr; // No left tree
        } else {
            root->left = new TreeNode(pre_order[start]);
            buildTree(root->left, pre_order, start+1, right_tree_start-1);
        }

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
