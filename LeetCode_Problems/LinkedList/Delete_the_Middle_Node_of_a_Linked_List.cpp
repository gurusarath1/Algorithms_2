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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return nullptr;
        
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        ListNode* prev_ptr = nullptr;
        
        while(slow_ptr != nullptr && fast_ptr != nullptr && fast_ptr->next != nullptr) {
            prev_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        
        prev_ptr->next = slow_ptr->next;
        
        return head;
        
    }
};
