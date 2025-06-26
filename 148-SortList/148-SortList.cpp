// Last updated: 6/26/2025, 7:58:21 PM
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // Base case: Empty or single-node list
        
        // Extract values into a vector
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the values
        sort(arr.begin(), arr.end());

        // Reconstruct the sorted linked list
        ListNode* newhead = new ListNode(arr[0]);
        ListNode* mover = newhead; // Pointer to traverse the new list
        for (int i = 1; i < arr.size(); i++) {
            mover->next = new ListNode(arr[i]);
            mover = mover->next;
        }

        return newhead;
    }
};
