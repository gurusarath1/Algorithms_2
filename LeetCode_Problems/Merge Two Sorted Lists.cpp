/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* output = new ListNode;
        ListNode* output_2 = output;
        
        while(l1 != nullptr && l2 != nullptr) {
            
            if(l1->val < l2->val) {
                
                output->next = new ListNode(l1->val);
                l1 = l1->next;
                output = output->next;
                
            } else if (l2->val < l1->val) {
                
                output->next = new ListNode(l2->val);
                l2 = l2->next;
                output = output->next;
                
            } else {
                output->next = new ListNode(l1->val);
                l1 = l1->next;
                output = output->next;
                output->next = new ListNode(l2->val);
                l2 = l2->next;
                output = output->next;
            }
            
        }
        
        while(l1 != nullptr) {
            output->next = new ListNode(l1->val);
            l1 = l1->next;
            output = output->next;
        }
        
        while(l2 != nullptr) {
            output->next = new ListNode(l2->val);
            l2 = l2->next;
            output = output->next;
        }
        
        return output_2->next;
        
    }
};
