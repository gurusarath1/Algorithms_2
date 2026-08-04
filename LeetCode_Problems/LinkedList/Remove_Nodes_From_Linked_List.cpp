/**

You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

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
    ListNode* removeNodes(ListNode* head) {

        pair<int,ListNode*> right_side = removeNodes_support(head, NULL);

        return right_side.second;
    }

    // pair<int,ListNode*> -- max val to right and the node with max val
    pair<int,ListNode*> removeNodes_support(ListNode* node, ListNode* prev) {
        if(node == NULL) {
            return pair<int,ListNode*>(0, NULL); // right most is NULL node
        }

        pair<int,ListNode*> right_side = removeNodes_support(node->next, node);

        if(right_side.first > node->val) {
            if(prev) prev->next = right_side.second;
            return right_side;
        }

        return pair<int,ListNode*>(node->val, node);
    }
};
