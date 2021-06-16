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
    ListNode* plusOne(ListNode* head) {
        
        int carry = support_plusOne(head);
        
        if(carry == 1) {
            
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            
            return newHead;
            
        } else {
            return head;
        }
        
    }
    
    int support_plusOne(ListNode* node) {
        
        if(node->next == nullptr) {
            if(node->val + 1 > 9) {
                node->val = 0;
                return 1;
            } else {
                node->val += 1;
                return 0;
            }
        }
        
        int carry = support_plusOne(node->next);

        if(node->val + carry > 9) {
            node->val = 0;
            return 1;
        } else {
            node->val += carry;
            return 0;
        }
        
    }
};
