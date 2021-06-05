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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev_node = nullptr;
        ListNode* node = head;
        ListNode* NewHead = head->next;
        ListNode* node1;
        ListNode* node2;
        ListNode* node3;
        
        while(node != nullptr) {
            
            node1 = node;
            node2 = node1->next;
            
            if(node2 == nullptr) break;
            
            node3 = node2->next;
            
            node2->next = node1;
            node1->next = node3;
            
            if(prev_node != nullptr) prev_node->next = node2;
            
            prev_node = node;
            node = node3;
        }
        
        return NewHead;
        
    }
};
