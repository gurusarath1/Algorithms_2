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
    int pairSum(ListNode* head) {

        deque<int> dq;

        ListNode* root = head;
        while(root != nullptr) {
            dq.push_back(root->val);
            root = root->next;
        }

        int max_twin_sum = 0;
        while(!dq.empty()) {
            int twin_sum = dq.front() + dq.back();

            if(max_twin_sum < twin_sum) max_twin_sum = twin_sum;

            dq.pop_back();
            dq.pop_front();
        }

        return max_twin_sum;
        
    }
};
