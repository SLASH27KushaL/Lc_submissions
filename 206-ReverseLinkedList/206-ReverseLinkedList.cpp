// Last updated: 6/26/2025, 7:57:58 PM
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
        //iterative
        if(head==NULL || head->next==NULL){
            return head;
        }        
       ListNode* newhead=reverseList(head->next);
       ListNode* front=head->next;
       front->next=head;
       head->next=NULL;
       return newhead;
    }
};