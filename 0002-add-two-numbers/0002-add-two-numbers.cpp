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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;               // Initialize carry to handle sums greater than 9
        ListNode *ans = NULL;        // Pointer to store the head of the result list
        ListNode *p = NULL;          // Pointer to keep track of the last node in the result list

        // Loop until both lists are fully traversed and there's no carry left
        while (l1 != NULL || l2 != NULL || carry != 0) {

            // Get the current digits from the lists, or 0 if the list is NULL
            int digit1 = l1 == NULL ? 0 : l1->val;
            int digit2 = l2 == NULL ? 0 : l2->val;

            // Calculate the digit to be added to the result and the new carry
            int digit = (digit1 + digit2 + carry) % 10;
            carry = (digit1 + digit2 + carry) / 10;

            // Create a new node with the calculated digit
            ListNode *temp = new ListNode(digit);

            // If this is the first node, initialize the result list
            if (ans == NULL)
                ans = temp;
            else
                p->next = temp;  // Link the new node to the last node in the result list

            p = temp;  // Move the pointer to the new last node

            // Move to the next nodes in the input lists (if they exist)
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }

        return ans;  // Return the head of the resulting linked list
    }
};