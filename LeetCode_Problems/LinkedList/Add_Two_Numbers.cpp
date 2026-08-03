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

        int cry = 0;
        ListNode* prev = NULL;
        ListNode* head = NULL;
        while(l1 || l2) {

            int num1 = 0;
            int num2 = 0;

            if(l1) num1 = l1->val;
            if(l2) num2 = l2->val;

            int sum = num1 + num2 + cry;
            int dig = 0;
            if(sum > 9) {
                dig = sum - 10;
                cry = 1;
            } else {
                dig = sum;
                cry = 0;
            }
            ListNode* digit = new ListNode(dig);

            if(prev != NULL) {
                prev->next = digit;
            } else {
                head = digit;
            }

            prev = digit;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(cry) {
            ListNode* digit = new ListNode(1);
            prev->next = digit;
        }

        return head;
    }
};
