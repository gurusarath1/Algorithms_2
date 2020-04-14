/**

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int Num1 = getDigit(l1);
        int Num2 = getDigit(l2);
        int Num3 = Num1 + Num2;
        
        ListNode* l = new ListNode;
        ListNode* l_ret = l;
        
        int digit = 0;
        while(Num3 > 0)
        {
            
            digit = Num3%10;
            Num3 = Num3 / 10;
            
            l->val = digit;
            
            if(Num3 > 0)
                l->next = new ListNode(digit);
                l = l->next;
        }
        
        return l_ret;
        
    }
    
    int getDigit(ListNode* l1)
    {
        int num=0;
        if(l1->next != NULL)
            num = getDigit(l1->next);
        
        return num*10 + l1->val;
        
    }
};
