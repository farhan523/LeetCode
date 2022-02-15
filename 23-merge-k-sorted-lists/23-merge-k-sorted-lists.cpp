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
#include <vector>
#include <algorithm>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> g1;
        int size = lists.size();
        ListNode* newHead = NULL;
        ListNode* newNode = NULL;
         ListNode* previous = NULL;
        for(int i=0;i<size;i++){
            while(lists[i] != NULL){
                 g1.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        
        sort(g1.begin(), g1.end());
        for(int i =0 ;i<g1.size();i++){
            newNode = new ListNode;
            newNode->val = g1[i];
            if(previous == NULL){
                previous = newNode;
            }else{
                previous->next = newNode;
                previous = newNode;
            }
            if(newHead == NULL){
                newHead = newNode;
            }
        }
            return newHead;
    }
};