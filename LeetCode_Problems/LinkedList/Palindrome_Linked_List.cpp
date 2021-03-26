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
    bool isPalindrome(ListNode* head) {
        
        ListNode* node_fast = head;
        ListNode* node_slow = head;
        
        if(head == nullptr) return false; // Linked list with 0 elements
        if(head->next == nullptr) return true; // Linked list with 1 element
        
        // Goto the center
        while(node_fast != nullptr && node_fast->next != nullptr) {
            node_fast = node_fast->next->next;
            node_slow = node_slow->next;
        }
        
        // Linked list with 2 element
        if(node_slow == nullptr) {
            if(head->val == head->next->val) return true; 
            else return false;
        }
        
        ListNode* prev_node = nullptr;
        ListNode* next_node = nullptr;
        
        // Reverse linked list from center
        while(node_slow != nullptr) {
            next_node = node_slow->next;
            node_slow->next = prev_node;
            prev_node = node_slow;
            node_slow = next_node;
        }
        
        // Check if both halfs are same
        ListNode* second_half_head = prev_node;
        ListNode* node = head;
        while(second_half_head != nullptr && node != nullptr) {
            if(second_half_head->val != node->val) {
                return false;
            }
            second_half_head = second_half_head->next;
            node = node->next;
        }
        
        return true;
        
    }
};
