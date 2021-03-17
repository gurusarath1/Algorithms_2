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
        
        ListNode* node;
        map<ListNode*, int> visited_map;
        
        node = headA;
        while(node !=  nullptr) {
            
            visited_map[node] = 1;
            node = node->next;
            
        }
        
        node = headB;
        
        while(node !=  nullptr) {
            
            if(visited_map[node] == 1) return node;
            node = node->next;
            
        }
        
        return nullptr;
        
        
    }
};
