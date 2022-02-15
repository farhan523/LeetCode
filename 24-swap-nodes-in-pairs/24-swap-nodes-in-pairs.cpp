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
    
   void swapNodes(ListNode* &prev,ListNode*  node1,ListNode*  node2){
       
           if(node2 == NULL)
                return;
      
       ListNode* tempNode = node2;
        node1->next = node2->next;
        tempNode->next = node1;
          if(prev == NULL){
            prev = node1;
        }  else{
            prev->next = node2;
            prev = node1;
        }     
        
        return;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode * tempNode = head;
        if(head == NULL)
                return head;
        if(head->next != NULL)
            head = head->next;
        ListNode * prev = NULL;
        ListNode* previous2 = NULL;
        while(tempNode != NULL){
            
            if(tempNode->next == NULL)
                    break;
                else
                    prev = tempNode;
             swapNodes(previous2,tempNode,tempNode->next);
                if(prev->next && prev->next->next)
                    tempNode = prev->next;
                else
                    break;
        }
            
        return head;
    }
};