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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>temp;
        ListNode* prev = NULL;
        ListNode*  tempNode = head;
        while(tempNode != NULL){
            if(prev == NULL){
                prev = tempNode;
                tempNode = tempNode->next;
            }else{
                if(prev->val == tempNode->val){
                    ListNode* tempHold = tempNode;
                    tempNode = tempNode->next;
                    prev->next = tempNode;
                    delete tempHold;
                }else{
                    prev = tempNode;
                    tempNode = tempNode->next;
                }
            }
        }
        return head;
    }
};