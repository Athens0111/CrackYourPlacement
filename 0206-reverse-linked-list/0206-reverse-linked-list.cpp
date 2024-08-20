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
    /*
        // Iterative solution to reverse a linked list
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;  // Initialize prev pointer to keep track of the previous node
            ListNode *curr = head;     // Initialize curr pointer to traverse the linked list
            ListNode *nxt;             // Pointer to store the next node during traversal

            // Traverse the list and reverse the links
            while(curr){
                nxt = curr->next;      // Store the next node before breaking the link
                curr->next = prev;     // Reverse the link: point current node to the previous node
                prev = curr;           // Move prev to the current node
                curr = nxt;            // Move curr to the next node in the list
            }

            return prev;  // Return the new head of the reversed list
        }
    */

    // Recursive solution to reverse a linked list
    ListNode* result(ListNode *curr, ListNode* prev) {
        if(!curr)  // Base case: if curr is null, return prev as the new head
            return prev;

        ListNode *ans = result(curr->next, curr);  // Recursively reverse the rest of the list
        curr->next = prev;  // Reverse the link for the current node by pointing it to the previous node

        return ans;  // Return the new head of the reversed list
    }

    // Wrapper function to reverse the linked list using recursion
    ListNode* reverseList(ListNode *head) {
        ListNode *ans = result(head, NULL);  // Start the recursion with the head node and NULL as the previous node
        return ans;  // Return the head of the reversed list
    }
};