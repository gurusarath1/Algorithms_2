/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* p = new ListNode;
        ListNode* p_temp = p;
        ListNode* num1 = l1;
        ListNode* num2 = l2;
        int digit1 = 0, digit2 = 0;
        int digitsum = 0;
        int carry = 0;
        
        while(num1 != nullptr && num2 != nullptr) {
            
            digit1 = num1->val;
            digit2 = num2->val;
            
            digitsum = digit1 + digit2 + carry;
            
            p_temp->next = new ListNode(digitsum % 10);
            carry = digitsum/10;
            
            num1 = num1->next;
            num2 = num2->next;
            p_temp = p_temp->next;
            
        }
        
        while(num1 != nullptr) {
            
            if(carry == 1) {
                p_temp->next = new ListNode( (num1->val + 1)%10 );
                
                if(num1->val + 1 >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }

            } else {
                p_temp->next = new ListNode(num1->val);
            }
            
            p_temp = p_temp->next;
            num1 = num1->next;
        }
        
        while(num2 != nullptr) {
            
            if(carry == 1) {
                
                p_temp->next = new ListNode( (num2->val + 1)%10 );
                if(num2->val + 1 >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                
            } else {
                p_temp->next = new ListNode(num2->val);
            }
            
            p_temp = p_temp->next;
            num2 = num2->next;
        }
        
        if(carry == 1) {
            p_temp->next = new ListNode(1);
        }
        
        
        return p->next;
        
    }
};
