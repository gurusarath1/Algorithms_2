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
    ListNode* reverseList(ListNode* head) {
        
        stack<ListNode*> nodes;
        ListNode* current_node = head;
        
        if(head == nullptr) {
            return nullptr;
        }
        
        while(current_node != nullptr) {
            nodes.push(current_node);
            current_node = current_node->next;
        }
        
        ListNode* last_node = nodes.top();
        
        while(!nodes.empty()) {
            current_node = nodes.top();
            nodes.pop();
            
            if(!nodes.empty()) {
                current_node->next = nodes.top();
            } else {
                current_node->next = nullptr;
            }
        }
        
        return last_node;
        
    }

};
