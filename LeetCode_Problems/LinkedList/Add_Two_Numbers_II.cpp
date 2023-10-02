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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> l1_s;
        stack<int> l2_s;
        stack<int> o_s;
        ListNode* o = nullptr;

        while(l1 != nullptr) {
            l1_s.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2 != nullptr) {
            l2_s.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        while(!l1_s.empty() && !l2_s.empty()) {
            int d1 = l1_s.top();
            int d2 = l2_s.top();
            int sum = d1 + d2 + carry;

            if(sum >= 10) {
                carry = 1;
                o_s.push(sum - 10);
            } else {
                carry = 0;
                o_s.push(sum);
            }

            l1_s.pop();
            l2_s.pop();
        }

        while(!l1_s.empty()) {
            int d1 = l1_s.top();
            int sum = d1 + carry;

            if(sum >= 10) {
                carry = 1;
                o_s.push(sum - 10);
            } else {
                carry = 0;
                o_s.push(sum);
            }

            l1_s.pop();
        }

        while(!l2_s.empty()) {
            int d1 = l2_s.top();
            int sum = d1 + carry;

            if(sum >= 10) {
                carry = 1;
                o_s.push(sum - 10);
            } else {
                carry = 0;
                o_s.push(sum);
            }

            l2_s.pop();
        }

        if(carry == 1) {
            // Becomes head node
            o = new ListNode(1,  nullptr);
        }

        ListNode* o_temp = o;
        while(!o_s.empty()) {
            if(o_temp == nullptr) {
                // Becomes head node
                o_temp = new ListNode(o_s.top(),  nullptr);
                o = o_temp;
            } else {
                o_temp->next = new ListNode(o_s.top(),  nullptr);
                o_temp = o_temp->next;
            }

            o_s.pop();
        }

        return o;
    }
};
