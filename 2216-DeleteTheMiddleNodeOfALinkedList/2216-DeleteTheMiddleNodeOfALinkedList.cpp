// Last updated: 6/26/2025, 7:54:43 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If the list has only one node, return nullptr
        if (head == nullptr || head->next == nullptr) {
        // Free the single node
            return nullptr;
        }
       
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Use two-pointer approach to find the middle node
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        prev->next = slow->next;
        delete slow;
        return head;
    }
};
