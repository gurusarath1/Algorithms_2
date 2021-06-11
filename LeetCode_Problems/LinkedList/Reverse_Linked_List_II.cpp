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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        if(head == nullptr || head->next == nullptr || left == right) return head;
        
        int len = right - left + 1;
        
        ListNode* current_node = head;
        ListNode* next_node;
        ListNode* prev_node = nullptr;
        
        ListNode* StartNode;
        ListNode* EndNode_inChain;
        
        
        int index = 1;
        while(current_node != nullptr){
            
            if(index == left) {
                
                StartNode  = prev_node;
                prev_node = nullptr;
                EndNode_inChain = current_node;
                for(int i=0; i<len; i++) {
                    
                    next_node = current_node->next;
                    current_node->next = prev_node;
                    prev_node = current_node;
                    current_node = next_node;
                    
                }
                
                if(left != 1) StartNode->next = prev_node;
                EndNode_inChain->next = current_node;
                
                if(left == 1) {
                    
                    return prev_node;
                    
                } else {
                    
                    return head;
                    
                }
                
                
            } else {
                
                prev_node = current_node;
                current_node = current_node->next;
                
            }
            
            index++;
            
        }
        
        return head;
        
    }
};
