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
    string gameResult(ListNode* head) {

        int odd_pts = 0;
        int even_pts = 0;
        while(head) {

            if(head->val > head->next->val) {
                even_pts++;
            } else if(head->val < head->next->val) {
                odd_pts++;
            }

            head = head->next->next;
        }

        if(odd_pts > even_pts) {
            return "Odd";
        } else if(odd_pts < even_pts) {
            return "Even";
        } else {
            return "Tie";
        }
        
    }
};
