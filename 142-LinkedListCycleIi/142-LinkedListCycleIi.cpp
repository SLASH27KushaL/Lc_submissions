// Last updated: 6/26/2025, 7:58:26 PM
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
      //where the node begins

      ListNode* slow=head;
      ListNode* fast=head;
      int flag=0;
      while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            flag=1;
            break;
        }
      }
      if(flag==0){
        return nullptr;
      }
      slow=head;
      while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
      }
      return slow;
        
        
    }
    
};