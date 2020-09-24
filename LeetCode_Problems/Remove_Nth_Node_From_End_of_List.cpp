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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* second_node = head->next;
        
        int size = removeNthFromEnd_support(nullptr, head, n);
        
        if(size-1 == n) { // Check if first node had to be deleted
            return second_node;
        } else {
            return head;
        }
        
    }
    
    int removeNthFromEnd_support(ListNode* prev_node, ListNode* node, int n) {
        
        int my_pos_from_end;
        
        if(node->next == nullptr) {
            my_pos_from_end = 1; // Last element in the linked list
        }
        
        if(node->next != nullptr) {
            my_pos_from_end = removeNthFromEnd_support(node, node->next, n);
        }

        if(my_pos_from_end == n) {
            
            if(prev_node != nullptr) { // What is the node the first node of LL ?
                prev_node->next = node->next;    
            }
            
            node->next = nullptr;
            return my_pos_from_end + 1;
        }
        
        return my_pos_from_end + 1;
        
    }
};
