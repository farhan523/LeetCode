/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*>tempS;
        ListNode* temp = head;
        while(temp != NULL){
            if(tempS.find(temp) != tempS.end()){
                return temp;
            }
            tempS.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};