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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        set<int> nums_set;
        // convert the vector to a set for faster lookup
        for(int i=0; i<nums.size(); i++) {
            nums_set.insert(nums[i]);
        }
        
        ListNode* node = head;
        int numberOfComponents = 0;
        bool prev_missed_flag = true; // flag that indicates if the previous item was missing
        while(node != nullptr) {
            
            if(nums_set.find(node->val) == nums_set.end()) {
                
                if(!prev_missed_flag) { // if consecutive components are missing it does not create new components
                    numberOfComponents++;
                    prev_missed_flag = true;
                }
                
            } else {
                prev_missed_flag = false;
            }
            
            node = node->next;
            
        }
        
        if(prev_missed_flag) return numberOfComponents; // If the last number is missing => it does not create a additional  component
        
        return numberOfComponents + 1; // if one number is missing in the middle then we get two parts // thats why there is a +1
        
        
        
    }
};
