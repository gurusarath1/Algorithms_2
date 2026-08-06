/**

Given the head of a linked list, return the list after sorting it in ascending order.

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
    ListNode* sortList(ListNode* head) {

        return mergeSort(head);
    }

    ListNode* getMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == NULL) return NULL;

        ListNode* prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev) prev->next = NULL;
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode* head = NULL;
        ListNode* curr_node = head;

        while(l1 && l2) {

            if(l1->val < l2->val) {
                if(head == NULL) {
                    head = l1;
                    curr_node = l1;
                } else {
                    curr_node->next = l1;
                    curr_node = curr_node->next;
                }

                l1 = l1->next;
            } else {
                if(head == NULL) {
                    head = l2;
                    curr_node = l2;
                } else {
                    curr_node->next = l2;
                    curr_node = curr_node->next;
                }
                l2 = l2->next;
            }

        }

        if(l1) {
            if(head == NULL) {
                head = l1;
            } else {
                curr_node->next = l1;
            }
        }

        if(l2) {
            if(head == NULL) {
                head = l2;
            } else {
                curr_node->next = l2;
            }
        }

        return head;
    }

    ListNode* mergeSort(ListNode* head) {

        ListNode* mid_node = getMidNode(head);

        if(mid_node == head) {
            return head;
        }

        ListNode* left_head = mergeSort(head);
        ListNode* right_head = mergeSort(mid_node);
        return merge(left_head, right_head);
    }
};
