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
    
    ListNode* reverse(ListNode* head) {
        
        if(head == nullptr) return nullptr;
        
        ListNode* prev_node = nullptr;
        ListNode* current_node = head;
        ListNode* next_node;
        
        while(current_node !=  nullptr) {
            next_node = current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_node;
        }
        
        return prev_node;
        
    }
    
    void reorderList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return;
        
        
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        
        ListNode* prev_node = nullptr;
        while(slow_ptr != nullptr && fast_ptr != nullptr && fast_ptr->next != nullptr) {
            prev_node = slow_ptr;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        
        prev_node->next = nullptr;
        ListNode* head_second_half = reverse(slow_ptr);
        
        ListNode* current_node = head;
        ListNode* next_node;
        ListNode* current_node_second_half = head_second_half;
        ListNode* next_node_second_half;
        while(current_node != nullptr) {
            
            next_node = current_node->next;
            current_node->next = current_node_second_half;
            current_node = next_node;
            
            prev_node = current_node_second_half;
            next_node_second_half = current_node_second_half->next;
            current_node_second_half->next = next_node;
            current_node_second_half = next_node_second_half;
        }
        
        // We might have one extra node in the second half
        // This case will enter if we have odd number of nodes in the linked list
        if(current_node_second_half != nullptr) {
            prev_node->next = current_node_second_half;
        }
        
    }
    
    
};
