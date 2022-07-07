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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;
        ListNode* tempNode = head;
        int size = 0;
        while(tempNode != NULL){
            tempNode = tempNode->next;
            size++;
        }
        int n = k % size;
        if(size == 1 || k == size || n == 0)
            return head;
        
       
        ListNode* newHead;
        int i = 0;
        tempNode = head;
        while(i < size - n){
            if(i + 1 >= size - n){
                ListNode* tail = head;
                head = head->next;
                tail->next = NULL;
                break;
            }
            head = head->next;
            i++;
            
        }
        ListNode* temp2 = head;
        while(temp2 != NULL){
            if(temp2->next == NULL){
                temp2->next = tempNode;
                break;
            }
            temp2 = temp2->next;
        }
        return head;
    }
};