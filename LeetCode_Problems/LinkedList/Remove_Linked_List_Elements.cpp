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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* prev_node = nullptr;
        ListNode* node = head;
        
        while(node != nullptr && node->val == val) { // Check if head has to be updated
            node = node->next;
        }
        
        // This happens if head == NULL or all elements in the linked list have the same val
        if(node == nullptr) return nullptr;
        
        head = node; // Update Head (not necessarily new head)
        prev_node = node; //Head node (First node whose value != val)
        node = node->next; // Second node
        
        while(node != nullptr) {
            if(node->val == val) {
                prev_node->next = node->next; // Create the skip connection
                node = node->next;
                continue; // Do not update prev (previous does not change)
            }
            
            prev_node = node;
            node = node->next;   
        }
        
        return head;
    }
};
