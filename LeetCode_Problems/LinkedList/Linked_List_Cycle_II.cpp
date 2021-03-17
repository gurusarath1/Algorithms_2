/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        int loop_detected = false;
        
        // Check if loop exist
        while(fast_ptr != nullptr && fast_ptr->next != nullptr) {
            
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            
            if(fast_ptr == slow_ptr) {
                loop_detected = true;
                break;
            }
            
        }
        
        // if loop exist
        if(loop_detected) {
            
            int cycle_len = 1; // start form 1 (since we already moved 1 step)
            slow_ptr = slow_ptr->next;
            
            // Find the length of the loop
            while(slow_ptr != fast_ptr) {
                slow_ptr = slow_ptr->next;
                cycle_len++;
            }
            
            
            slow_ptr = head;
            fast_ptr = head;
            
            // offset the fast point loop length number of times
            for(int i=0; i<cycle_len; i++) {
                fast_ptr = fast_ptr->next;
            }
            
            // Loop until they meet (both move 1 step at a time)
            while(slow_ptr != fast_ptr) {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
                cycle_len++;
            }
            
            // Meeting point is the loop start
            return slow_ptr;
            
            
        }
        
        return nullptr; // No loop
    }
};
