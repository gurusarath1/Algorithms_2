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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* current_ptr = head;
        ListNode* prev_ptr = nullptr;
        
        while(current_ptr != nullptr) {
            
            prev_ptr = current_ptr;
            current_ptr = current_ptr->next;
            
            if(current_ptr != nullptr && prev_ptr->val == current_ptr->val) {
                
                while(current_ptr != nullptr && current_ptr->val == prev_ptr->val) {
                    current_ptr = current_ptr->next;
                }
                
                prev_ptr->next = current_ptr;
            }
            
            
        }
        
        return head;
        
    }
};
