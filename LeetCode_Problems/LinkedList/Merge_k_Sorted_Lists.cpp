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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) {
            return nullptr;
        }
        
        if(lists.size() == 1) {
            return lists[0];
        }
        
        int numLists = lists.size();
        vector<ListNode*> list_ptrs(numLists);
        int num_lists_complete = 0;
        int smallestNode_index;
        int smallestVal = INT_MAX;
        ListNode* newLinkedList_ptr = nullptr;
        ListNode* newLinkedList = nullptr;
        
        for(int i=0; i<numLists; i++) {
            list_ptrs[i] = lists[i];
        }
        
        while(num_lists_complete < numLists) {
            
            smallestNode_index = -1;
            smallestVal = INT_MAX;
            
            for(int i=0; i<lists.size(); i++) {
                
                if(list_ptrs[i] != nullptr && list_ptrs[i]->val < smallestVal) {
                    smallestVal = list_ptrs[i]->val;
                    smallestNode_index = i;
                }
                
            }
            
            if(smallestNode_index == -1) { // lists contains only empty linked lists
                break;
            }
            
            if(newLinkedList_ptr == nullptr) {
                newLinkedList_ptr = list_ptrs[smallestNode_index];
                newLinkedList = newLinkedList_ptr;
            } else {
                newLinkedList_ptr->next = list_ptrs[smallestNode_index];
                newLinkedList_ptr = newLinkedList_ptr->next;
                
            }
            
            
            list_ptrs[smallestNode_index] = list_ptrs[smallestNode_index]->next;
            
            if(list_ptrs[smallestNode_index] == nullptr) {
                num_lists_complete++;
            }
            
        }
        
        return newLinkedList;
    }
};
