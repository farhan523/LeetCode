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
        map<int,int> tmp;
        ListNode* tempHead = head;
        ListNode* prev = NULL;
        while(tempHead != NULL){
           if( tmp.find(tempHead->val) == tmp.end()){
               tmp.insert({tempHead->val,1});
              
              
           }else{
               tmp.find(tempHead->val)->second++;
              
           }
             tempHead = tempHead->next;
        }
        
        tempHead = head;
        prev = NULL;
        while(tempHead != NULL){
            if(tmp.find(tempHead->val)->second >= 2){
                  ListNode* temp = tempHead;
                if(prev){
                    prev->next = tempHead->next;
                    tempHead = tempHead->next;
                    
                }else{
                    head = tempHead->next;
                    tempHead = tempHead->next;
                    
                }
                delete temp;
            }else{
                prev = tempHead;
                tempHead = tempHead->next;
            }
            
        }
        return head;
    }
};