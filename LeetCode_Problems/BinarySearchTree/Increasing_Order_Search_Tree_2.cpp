class Solution {
public:
    
    TreeNode* LL;
    TreeNode* head;
    
    TreeNode* increasingBST(TreeNode* root) {
        
        LL = nullptr;
        head = nullptr;
        increasingBST_support(root);
        
        return head;
        
    }
    
    void increasingBST_support(TreeNode* node) {
        
        if(node == nullptr) {
            return;
        }
        
        increasingBST_support(node->left);
        
        if(LL == nullptr) {
            LL = node;
            head = node;
        } else {
            node->left = nullptr;
            LL->right = node;
            LL = LL->right;
        }
        
        increasingBST_support(node->right);
        
        
    }
};
