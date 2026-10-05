/**
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node.
That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed).
If the ith node does not have a next greater node, set answer[i] = 0.
**/

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
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> ret;
        stack<pair<int,int>> stk;
        map<pair<int,int>,int> ans;

        ListNode* nd = head;
        int i = 0;
        while(nd) {
            while(!stk.empty() && nd->val > stk.top().first) {
                ans[stk.top()] = nd->val;
                stk.pop();
            }

            stk.push( pair<int,int>{nd->val, i} );
            nd = nd->next;
            i++;
        }

        nd = head;
        i = 0;
        while(nd) {
            pair<int,int> val_idx = {nd->val,i};
            if(ans.find(val_idx) != ans.end()) {
                ret.push_back(ans[val_idx]);
            } else {
                ret.push_back(0);
            }

            nd = nd->next;
            i++;
        }
        
        return ret;
    }
};
