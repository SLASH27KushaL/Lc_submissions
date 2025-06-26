// Last updated: 6/26/2025, 7:58:25 PM
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* secondHead = reverse(slow->next);
        slow->next = NULL; // Disconnect the two halves

        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = secondHead;
        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

