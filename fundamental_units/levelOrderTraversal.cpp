TreeNode* levelOrderTraversal(TreeNode* root) {

    queue<TreeNode*> q;

    q.push(root);
    while(!q.empty()) {

        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);

        cout << q.front()->val << endl;

        q.pop();

    }

    return root;
}
