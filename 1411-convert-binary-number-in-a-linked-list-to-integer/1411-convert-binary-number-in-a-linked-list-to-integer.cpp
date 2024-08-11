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
    int getDecimalValue(ListNode* head) {
        int c = -1;         // Counter to determine the position of each bit
        ListNode *p = head; // Pointer to traverse the linked list
        int ans = 0;        // Variable to store the resulting decimal value

        // First loop to count the number of nodes and determine the position of the highest bit
        while (p) {
            c++;
            p = p->next;
        }

        // Reset pointer to the head of the list for the second traversal
        p = head;

        // Second loop to calculate the decimal value by shifting bits
        while (p) {
            if (p->val) 
                ans += (1 << c); // Add the value of the current bit (1 << c) to the result
            c--;                 // Move to the next lower bit position
            p = p->next;         // Move to the next node in the list
        }

        // Return the calculated decimal value
        return ans;
    }
};