// Last updated: 6/26/2025, 7:58:15 PM
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        // Calculate lengths of both lists
        int count1 = 0, count2 = 0;
        ListNode *tempA = headA, *tempB = headB;
        while (tempA) {
            count1++;
            tempA = tempA->next;
        }
        while (tempB) {
            count2++;
            tempB = tempB->next;
        }

        // Align the starting points
        tempA = headA;
        tempB = headB;
        if (count1 > count2) {
            int diff = count1 - count2;
            while (diff--) tempA = tempA->next;
        } else {
            int diff = count2 - count1;
            while (diff--) tempB = tempB->next;
        }

        // Find the intersection point
        while (tempA && tempB) {
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr; // No intersection
    }
};
