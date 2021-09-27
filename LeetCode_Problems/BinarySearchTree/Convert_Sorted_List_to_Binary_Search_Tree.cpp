/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        ListNode* start = head;
        ListNode* end = head;
        int num_elements = 1;
        TreeNode* result_tree;
        
        if(head == nullptr) return nullptr;
        
        while(end->next != nullptr) {
            end = end->next;
            num_elements++;
        }
        
        buildTree(&result_tree, 0, num_elements, start, end);
        
        return result_tree;
    }
    
    void buildTree(TreeNode** root, int start_index, int end_index, ListNode* start, ListNode* end) {
        
        int num_elements = (end_index - start_index);
        
        if(num_elements == 1) {
            (*root) = new TreeNode(end->val, nullptr, nullptr);
            return;
        }
        
        if(num_elements == 2) {
            
            (*root) = new TreeNode(end->val, nullptr, nullptr);
            (*root)->left = new TreeNode(start->val, nullptr, nullptr);
            return;
        }
        
        if(num_elements == 3) {
            (*root) = new TreeNode(start->next->val, nullptr, nullptr);
            (*root)->left = new TreeNode(start->val, nullptr, nullptr);
            (*root)->right = new TreeNode(start->next->next->val, nullptr, nullptr);
            return;
        }
        
        
        vector<ListNode*> nodes = getMidNode(start, end);
        
        *root = new TreeNode(nodes[1]->val, nullptr, nullptr);
        
        buildTree(&((*root)->left), 0, num_elements/2, start, nodes[0]);
        
        if(num_elements%2 == 1)
            buildTree(&((*root)->right), 0, num_elements/2, nodes[2], end);
        else
            buildTree(&((*root)->right), 0, num_elements/2 - 1, nodes[2], end);
        
    }
    
    vector<ListNode*> getMidNode(ListNode* start, ListNode* end) {
        
        ListNode* fastPtr = start;
        ListNode* slowPtr = start;
        ListNode* prevPtr = nullptr;
        
        if(start == nullptr) vector<ListNode*> { nullptr, nullptr, nullptr };
        
        while(fastPtr != nullptr && fastPtr->next != nullptr && (fastPtr != end) ) {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            
            if(fastPtr->next == end) break;
            fastPtr = fastPtr->next->next;
        }
        
        return vector<ListNode*> { prevPtr, slowPtr, slowPtr->next };
        
    }
};
