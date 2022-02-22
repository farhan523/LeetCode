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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      
        ListNode* newHead = NULL;
        ListNode* previous = NULL;
        ListNode* newNode = NULL;
        ListNode* newNode2 = NULL;
        while(list1 != NULL && list2 != NULL){
            newNode = new ListNode;
            if(list1->val < list2->val){
                newNode->val = list1->val;
                list1 = list1->next;
            }else if(list1->val > list2->val){
                newNode->val = list2->val;
                list2 = list2->next;

            }else{
                newNode->val = list1->val;
                newNode2 = new ListNode;
                newNode2->val = list2->val;
                list1 = list1->next;
                list2 = list2->next;
                if(previous){
                previous->next = newNode;
                newNode->next = newNode2;
                previous = newNode2;
                }else{
                newNode->next = newNode2;
                previous = newNode2;
                }
                 if(newHead == NULL)
                        newHead = newNode;
                continue;
            }
            if(previous){
                previous->next = newNode;
                previous = newNode;
            }else{
                previous = newNode;
            }
            if(newHead == NULL)
                newHead = newNode;
        }
        
        while(list1 != NULL){
            newNode = new ListNode;
            newNode->val = list1->val;
            list1 = list1->next;
            if(newHead == NULL)
                newHead = newNode;
             if(previous){
                previous->next = newNode;
                previous = newNode;
            }else{
                previous = newNode;
            }
        }
        while(list2 != NULL){
            newNode = new ListNode;
            newNode->val = list2->val;
            list2 = list2->next;
             if(newHead == NULL)
                newHead = newNode;
             if(previous){
                previous->next = newNode;
                previous = newNode;
            }else{
                previous = newNode;
            }
        }
        return newHead;
    }
};