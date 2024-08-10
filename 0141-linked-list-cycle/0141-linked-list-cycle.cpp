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
        // Initialize two pointers, p and q, both starting at the head of the list
        ListNode *p = head;
        ListNode *q = head;

        // Traverse the list
        while (p && p->next) {
            // Move pointer p two steps forward
            p = (p->next)->next;
            // Move pointer q one step forward
            q = q->next;

            // If pointers p and q meet, a cycle is detected
            if (p == q)
                return true;
        }

        // If we reach here, there is no cycle in the list
        return false;
    }
};