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
        
        queue<int> num1;
        queue<int> num2;
        queue<int> result;
        
        while(l1 != nullptr) {
            num1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2 != nullptr) {
            num2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        int sum;
        while(!num1.empty() && !num2.empty()) {
            
            int digit_1 = num1.front();
            num1.pop();
            int digit_2 = num2.front();
            num2.pop();
            
            sum = digit_1 + digit_2 + carry;
            
            if(sum > 9) {
                carry = 1;
                sum = sum % 10;
            }  else {
                carry = 0;
            }
            
            result.push(sum);
        }
        
        while(!num1.empty()) {
            
            int digit_1 = num1.front();
            num1.pop();
            
            sum = digit_1 + carry;
            
            if(sum > 9) {
                carry = 1;
                sum = sum % 10;
            }  else {
                carry = 0;
            }
            
            result.push(sum);
        }
        
        while(!num2.empty()) {
            
            int digit_2 = num2.front();
            num2.pop();
            
            sum = digit_2 + carry;
            
            if(sum > 9) {
                carry = 1;
                sum = sum % 10;
            }  else {
                carry = 0;
            }
            
            result.push(sum);
        }
        
        if(carry == 1) {
            result.push(1);
        }
        
        ListNode* head;
        ListNode* prev_node = nullptr;
        while(!result.empty()) {
            ListNode* digit = new ListNode(result.front(), nullptr);
            result.pop();
            
            if(prev_node == nullptr) {
                prev_node = digit;
                head = digit;
            } else {
                prev_node->next = digit;
                prev_node = digit;
            }
        }
        
        return head;
    }
};
