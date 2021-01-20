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
        
        ListNode* ptr1;
        ListNode* ptr2;
        ListNode* prev_node = nullptr;
        
        ptr1 = head;
        ptr2 = head;
        
        // initialize pointer 2
        for(int i=0; i<n-1; i++) {
            
            if(ptr2->next != nullptr) {
                ptr2 = ptr2->next;
            } else {
                return head;
            }
            
        }
        

        while(ptr2 != nullptr) {
            
            ptr2 = ptr2->next;
            
            if(ptr2 == nullptr) break;
            prev_node = ptr1;
            ptr1 = ptr1->next;
            
        }
        
        cout << ptr1->val;
        
        if(prev_node != nullptr) { // Check if head has to be removed
            
            // Remove the node (not head)
            prev_node->next = ptr1->next;
            return head;
            
        } else { // First node has to be removed (head node)
            
            return head->next;
            
        }
        
        
    }
};
