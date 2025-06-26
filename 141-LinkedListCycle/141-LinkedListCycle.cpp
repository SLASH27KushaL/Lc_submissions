// Last updated: 6/26/2025, 7:58:28 PM
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
    bool hasCycle(ListNode *head) {
        if(head==nullptr){
            return false;
        }
     ListNode* slow=head;
     ListNode* fast=head;
     while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
     }
     return false;
    }
};