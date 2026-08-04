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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* nth_node = head;
        ListNode* last_node = head;
        ListNode* n_minus_one_node = NULL;

        int i=1;
        while(head) {
            if(i<n) {
                last_node = last_node->next;
            } else {

                if(last_node->next == NULL) break; // Reached last node
                n_minus_one_node = nth_node;
                nth_node = nth_node->next;
                last_node = last_node->next;
            }

            i++;
        }

        if(n_minus_one_node) {
            n_minus_one_node->next = nth_node->next; // skip nth node
        } else {
            head = head->next; // nth node is the first node
        }
        return head;

    }
};
