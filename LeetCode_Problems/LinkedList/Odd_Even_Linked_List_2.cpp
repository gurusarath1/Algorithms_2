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
        
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode* node = head;
        ListNode* NextNode;
        ListNode* PrevNode;
        ListNode* EvenNodeHead = head->next;
        
        int num_nodes = 0;
        while(node != nullptr && node->next != nullptr) {
            
            num_nodes++;
            NextNode = node->next;
            node->next = node->next->next;
            PrevNode = node;
            node = NextNode;
            
        }
        
        if(num_nodes % 2 != 0) PrevNode->next = EvenNodeHead; // If you reach the end of evevn Linked List
        else node->next = EvenNodeHead; // If you reach the end of odd linked list
        
        return head;
        
    }
};
