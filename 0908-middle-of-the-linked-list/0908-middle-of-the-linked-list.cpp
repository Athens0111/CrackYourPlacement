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
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers, p and q, both starting at the head of the list
        ListNode *p = head, *q = head;

        // Traverse the list with two pointers
        while (p && p->next) {
            // Move p two steps ahead (p will move faster)
            p = (p->next)->next;
            // Move q one step ahead (q will move slower)
            q = q->next;
        }
        // When p reaches the end of the list, q will be at the middle
        return q;
    }
};