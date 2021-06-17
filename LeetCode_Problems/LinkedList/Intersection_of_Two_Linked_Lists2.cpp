/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        
        bool switched1 = false;
        bool switched2 = false;
        
        while(node1 != node2) {
            
            node1 = node1->next;
            node2 = node2->next;
            
            if(node1 == nullptr) {
                
                if(switched1) return nullptr;
                
                switched1 = true;
                node1 = headB;
            }
            
            if(node2 == nullptr) {
                
                if(switched2) return nullptr;
                
                switched2 = true;
                node2 = headA;
            }
            
        }
        
        return node1;
        
    }
};
