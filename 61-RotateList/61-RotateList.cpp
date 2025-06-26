// Last updated: 6/26/2025, 7:59:26 PM
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
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k) {
     int len=0;
    
     ListNode* temp=head;
     while(temp!=NULL){
        len++;
        temp=temp->next;
     }
       if (!head || !head->next || k%len == 0) {
            return head;
    }
     int first_part=len-1-(k%len);
     ListNode* tempe=head;
     while(first_part--){
            tempe=tempe->next;
    }
     ListNode* newhead=tempe->next;
     tempe->next=NULL;
    // Traverse the rotated part to find the last node
ListNode* last = newhead;
if(last){
while (last->next) {
    last = last->next;
}}

     if(last)
     last->next=head;
     return newhead;
    }
};