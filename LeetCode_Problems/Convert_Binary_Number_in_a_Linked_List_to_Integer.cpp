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
    int getDecimalValue(ListNode* head) {
        
        if(head == nullptr) return 0;
        
        int value = 0;
        
        support_getDecimalValue(head, value);
        
        return value;
        
    }
    
    int support_getDecimalValue(ListNode* node, int &value){
        
        if(node == nullptr) {
            return -1;
        }
        
        int current_level = support_getDecimalValue(node->next, value);
        
        value += (node->val) * pow(2, 1 + current_level);
        
        return 1 + current_level;
        
    }
};
