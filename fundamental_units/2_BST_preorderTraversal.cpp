    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> stack_nodes;
        vector<int> result;
        
        if(root == nullptr) return result;
        
        stack_nodes.push(root);
        
        while(!stack_nodes.empty()) {
            
            TreeNode* current_node = stack_nodes.top();
            stack_nodes.pop();
            
            if(current_node->right != nullptr) stack_nodes.push(current_node->right);
            if(current_node->left != nullptr) stack_nodes.push(current_node->left);
            
            result.push_back(current_node->val);
        }
        
        return result;
        
    }
