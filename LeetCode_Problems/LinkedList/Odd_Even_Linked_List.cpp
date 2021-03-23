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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* node = head;
        ListNode* prev = head;
        
        if(head == nullptr) return nullptr;
        
        node = head->next;
        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        
        while(node != nullptr) {
            prev->next = node->next; // Create the skip connections
            prev = node;
            node = node->next;
        }
        
        node = odd_head;
        while(node->next != nullptr) node = node->next; // Goto the end of the odd linked list
        
        node->next = even_head; // Add the even head at the end of odd linked list
        
        return odd_head;

    }
};
