// Last updated: 6/26/2025, 7:59:55 PM
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1!=NULL && temp2!=NULL){
            
            if((temp1->val)>=(temp2->val)){
                temp->next=temp2;
                temp=temp->next;
                if(temp2){
                temp2=temp2->next;
            }
            }
            else{
                temp->next=temp1;
                temp=temp->next;
                temp1=temp1->next;            
                }
        }
        if(temp1!=NULL && temp2==nullptr){
            while(temp1!=NULL){
                temp->next=temp1;
                temp1=temp1->next;
                temp=temp->next;
            }
        }
        if(temp2!=NULL && temp1==NULL){
            while(temp2!=NULL){
                temp->next=temp2;
                temp2=temp2->next;
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};