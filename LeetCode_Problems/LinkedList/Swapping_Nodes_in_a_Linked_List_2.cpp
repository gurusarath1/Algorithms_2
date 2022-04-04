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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        
        int val1, val2;   
        for(int i=1; i<k; i++) {
            fast_ptr = fast_ptr->next;
        }
        
        ListNode* node1= fast_ptr;
        
        while(fast_ptr->next != nullptr) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        
        int temp = node1->val;
        node1->val = slow_ptr->val;
        slow_ptr->val = temp;
        
        return head;
    }
};
