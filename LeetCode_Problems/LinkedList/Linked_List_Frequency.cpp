/**

Given the head of a linked list containing k distinct elements,
return the head to a linked list of length k containing the frequency
of each distinctelement in the given linked list in any order.

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
    ListNode* frequenciesOfElements(ListNode* head) {
        map<int,int> freq;

        while(head) {
            freq[head->val] += 1;
            head = head->next;
        }

        ListNode* prev = NULL;
        ListNode* ret = NULL;
        for(auto &it : freq) {
            ListNode* f = new ListNode(it.second);

            if(prev == NULL) {
                prev = f;
                ret = prev;
            } else {
                prev->next = f;
                prev = f;
            }

        }

        return ret;
    }
};
