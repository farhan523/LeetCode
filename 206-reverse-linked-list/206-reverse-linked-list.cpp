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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* tempNext = NULL;
        ListNode* tempHead = head;
        while(tempHead != NULL){
           tempNext = tempHead->next;
            tempHead->next = prev;
            prev = tempHead;
            if(tempNext == NULL)
                return tempHead;
            tempHead = tempNext;
            
        }
        return head;
    }
};