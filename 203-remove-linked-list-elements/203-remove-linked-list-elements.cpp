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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tempNode = head;
        ListNode* prev = NULL;
        while(tempNode != NULL){
            if(tempNode->val == val){
                ListNode* tempHold = tempNode;
                if(prev == NULL){
                    
                    head = tempNode->next;
                    tempNode = tempNode->next;  
                    
                   
                }else{
                    prev->next = tempNode->next;
                    tempNode =  tempNode->next;
                    
                }
                delete tempHold;
            }else{
                prev = tempNode;
                tempNode = tempNode->next;
            }
        }
        return head;
    }
};