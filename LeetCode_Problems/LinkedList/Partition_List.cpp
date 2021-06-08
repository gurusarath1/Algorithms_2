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
    ListNode* partition(ListNode* head, int x) {
        
        
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* Newhead = nullptr;
        ListNode* temphead = nullptr;
        ListNode* NewlinkedList = nullptr;
        ListNode* NewlinkedList_temp = nullptr;
        
        while(head != nullptr) {
            
            if(head->val < x) {
                
                if(NewlinkedList == nullptr) {
                    NewlinkedList = head;
                    Newhead = head;
                } else {
                    NewlinkedList->next = head;
                    NewlinkedList = NewlinkedList->next;
                }
                
            } else {
                
                if(NewlinkedList_temp == nullptr) {
                    NewlinkedList_temp = head;
                    temphead = head;
                } else {
                    NewlinkedList_temp->next = head;
                    NewlinkedList_temp = NewlinkedList_temp->next;
                }

            }
            
            head = head->next;
        }
        
        if(temphead != nullptr) NewlinkedList_temp->next = nullptr;
        if(Newhead != nullptr) NewlinkedList->next = temphead;
        else Newhead = temphead;
        
        
        return Newhead;
        
    }
};
