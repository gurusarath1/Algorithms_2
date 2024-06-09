class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;

        stack<TreeNode*> q;
        set<TreeNode*> visited;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.top();
            if(node->left != nullptr && visited.find(node->left) == visited.end()) {
                q.push(node->left);
            } else {
                result.push_back(node->val);
                visited.insert(node);
                q.pop();
                if(node->right != nullptr) q.push(node->right);
            }
        }
        return result;
        
    }
};
