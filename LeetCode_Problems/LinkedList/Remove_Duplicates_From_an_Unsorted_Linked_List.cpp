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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        
        unordered_map<int,int> frequencyOfNode;
        
        ListNode* node = head;
        while(node != nullptr) {
            frequencyOfNode[node->val] += 1;
            node = node->next;
        }
        
        node = head;
        ListNode* prev_node = nullptr;
        ListNode* newHead = nullptr;
        bool newHeadDetected = false;
        while(node != nullptr) {
            
            if(frequencyOfNode[node->val] > 1) {
                
                if(prev_node != nullptr) {
                    prev_node->next = node->next;
                } else {
                    newHead = node->next;
                    newHeadDetected = true; // flag to indicate the head of the linked list has changed
                }
                
            } else {
                prev_node = node;
            }
            
            node = node->next;
            
        }
        
        /*
        if all the elements in the linked list are duplicates
        then the newhead will be a nullptr
        hence we use the newheadflag to detect it
        */
        
        if(newHeadDetected) return newHead;
        
        return head;
        
    }
};
