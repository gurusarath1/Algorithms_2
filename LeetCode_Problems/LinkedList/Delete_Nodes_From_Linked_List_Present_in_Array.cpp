/**
You are given an array of integers nums and the head of a linked list.
Return the head of the modified linked list after removing all nodes
from the linked list that have a value that exists in nums.

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> bag;
        for(int i : nums) {
            bag.insert(i);
        }

        ListNode* node = head;
        ListNode* new_head = head;
        ListNode* prev = NULL;
        while(node) {
            if(bag.find(node->val) == bag.end()) {
                // No need to delete; just advance pointers
                prev = node;
            } else {
                // Node to delete
                if(prev) {
                    prev->next = node->next;
                } else {
                    // node is head node; Delete head
                    new_head = node->next;
                }
            }

            node = node->next; // Always go to next node
        }

        return new_head;
    }
};
