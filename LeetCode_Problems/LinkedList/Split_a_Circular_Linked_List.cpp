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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {

        vector<ListNode*> ret;

        ListNode* slow = list;
        ListNode* fast = list;

        ret.push_back(list);

        while(1) {

            if(fast->next == list) {
                // Odd number of nodes
                fast->next = slow->next;
                ret.push_back(slow->next);
                slow->next = list;
                break;
            } else if(fast->next->next == list) {
                // Evern number of nodes
                fast->next->next = slow->next;
                ret.push_back(slow->next);
                slow->next = list;
                break;
            } else {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        
        return ret;
    }
};
