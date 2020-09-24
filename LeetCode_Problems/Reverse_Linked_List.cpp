/*
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

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


// Iterative Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* next_temp = nullptr;
        ListNode* current = head;
        
        while(current !=  nullptr) {
            
            next_temp = current->next;
            current->next = prev;
            prev = current;
            current = next_temp;
            
        }
        
        return prev;
        
        
    }
};



// Recursive Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* node = head;
        
        if(node == nullptr) {
            return node;
        }
        
        if(node->next == nullptr) {
            
            return node;
            
        }
        
        ListNode* NewHead = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        
        return NewHead;
        
    }

};
