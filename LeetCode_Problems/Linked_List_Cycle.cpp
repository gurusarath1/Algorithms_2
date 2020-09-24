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
    bool hasCycle(ListNode *head) {
        
        ListNode* node = head;
        map<ListNode*, int> visitedNodes;
        
        if(node == nullptr) {
            return false;
        }
        
        while(node != nullptr) {
            
            if(visitedNodes.find(node) == visitedNodes.end()) {
                visitedNodes[node] = 1;
            } else {
                return true;
            }
            
            node = node->next;
        }
        
        return false;
        
    }
};
