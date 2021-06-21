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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* current_node = head;
        ListNode* prev_node = nullptr;
        ListNode* next_node;
        ListNode* new_head;
        ListNode* last_node_of_k_group = head;
        
        if(k == 1) return head;
        
        for(int i=0; i<k; i++) {
            next_node = current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_node;
        }
        
        new_head = prev_node;
        

        while(current_node != nullptr) {
            
            int num_nodes_left = 0;
            ListNode* temp = current_node;
            while(temp != nullptr) {
                temp = temp->next;
                num_nodes_left++;
                if(num_nodes_left == k-1) last_node_of_k_group->next = temp;
            }
            
            if(!(num_nodes_left >= k)) {
                last_node_of_k_group->next = current_node;
                break;
            }
            
            
            prev_node = nullptr;
            last_node_of_k_group = current_node;
            for(int i=0; i<k; i++) {
                next_node = current_node->next;
                current_node->next = prev_node;
                prev_node = current_node;
                current_node = next_node;
            }
            
            
        }

        return new_head;
        
    }
};
