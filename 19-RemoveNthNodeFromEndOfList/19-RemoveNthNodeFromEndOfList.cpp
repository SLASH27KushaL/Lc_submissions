// Last updated: 6/26/2025, 7:59:58 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Handle edge case for a single node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Calculate the length of the list
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // If removing the first node
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Find the node just before the one to delete
        int count = len - n - 1;
        ListNode* temp1 = head;
        while (count--) {
            temp1 = temp1->next;
        }

        // Delete the nth node from the end
        ListNode* dele = temp1->next;
        temp1->next = temp1->next->next;
        delete dele;

        return head;
    }
};
