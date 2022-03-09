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
        
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* ptr_1 = head;
        ListNode* ptr_2 = head->next;
        ListNode* new_head;
        
        // Remove the duplicates in the beginning of the linkedlist (if any)
        // This takes care of finding new head
        while(ptr_2 != nullptr && ptr_2->val == ptr_1->val) {
            while(ptr_2 != nullptr && ptr_2->val == ptr_1->val) {
                ptr_2 = ptr_2->next;
            }
            
            if(ptr_2 != nullptr) {
                ptr_1 = ptr_2;
                ptr_2 = ptr_2->next;
            } else {
                return nullptr;
            }
        }
        
        new_head = ptr_1;
        ListNode* prev_node = nullptr;
        while(ptr_2 != nullptr) {
            
            if(ptr_1->val == ptr_2->val) {
                
                while(ptr_2 != nullptr && ptr_1->val == ptr_2->val) {
                    ptr_2 = ptr_2->next;
                }
                
                prev_node->next = ptr_2;
                
                if(ptr_2 != nullptr) {
                    ptr_1 = ptr_2;
                    ptr_2 = ptr_2->next;
                } else {
                    return new_head;
                }
                
            } else {
                prev_node = ptr_1;
                ptr_1 = ptr_1->next;
                ptr_2 = ptr_2->next;
            }
            
            
        }
        
        return new_head;
        
    }
};
