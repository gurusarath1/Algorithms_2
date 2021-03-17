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
        
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return nullptr; // Single element linked list
        
        for(int i=0; i<n; i++) {
            fast_ptr = fast_ptr->next;
        }
        
        if(fast_ptr == nullptr) { // This means the head node has to be removed
            return head->next;
        }
        
        while(fast_ptr != nullptr) {
            fast_ptr = fast_ptr->next;
            
            if(fast_ptr != nullptr) slow_ptr = slow_ptr->next;
        }
        
        slow_ptr->next = slow_ptr->next->next; // skip the node
        
        return head;
    }
};
