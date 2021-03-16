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
        
        int n = 1;
        ListNode* current_node_fast = head;
        ListNode* prev_node_fast = nullptr;
        
        ListNode* node1;

        while(n <= k) {
            prev_node_fast = current_node_fast;
            current_node_fast = current_node_fast->next;
            n++;
        }
        
        node1 = prev_node_fast;
        
        ListNode* current_node = head;

        while(current_node_fast != nullptr) {
            prev_node_fast = current_node_fast;
            current_node_fast = current_node_fast->next;

            current_node = current_node->next;
        }
        
        int temp;
        temp = current_node->val;
        current_node->val = node1->val;
        node1->val = temp;
        
        return head;
        
    }
};
