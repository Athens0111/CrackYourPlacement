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
/*  // Recursive solution
    ListNode* result(ListNode *start, ListNode *end, bool &res){
        if(!end){
            return start;
        }

        start = result(start, end->next, res);
        if(res && start->val == end->val){
            res = true;
        }
        else{
            res = false;
        }
        return start->next;
    }

    bool isPalindrome(ListNode* head) {
       bool res = true; 
       bool ans = result(head, head, res);
       return res; 
    }
*/

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;       // Initialize the previous pointer to NULL (end of the reversed list)
        ListNode* curr = head;       // Start with the current pointer at the head of the list

        // Iterate through the list, reversing the links between nodes
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;  // Temporarily store the next node
            curr->next = prev;                // Reverse the current node's pointer
            prev = curr;                      // Move the previous pointer to the current node
            curr = nextTemp;                  // Move to the next node in the original list
        }

        return prev;  // Return the new head of the reversed list (previously the last node)
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;  // If the list is empty or has only one node, it's a palindrome

        // Step 1: Find the middle of the list using the slow and fast pointers
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;           // Move slow pointer by one node
            fast = fast->next->next;     // Move fast pointer by two nodes
        }

        // Step 2: Reverse the second half of the list starting from the node after the slow pointer
        slow->next = reverseList(slow->next);
        ListNode* secondHalf = slow->next;  // The start of the reversed second half

        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        while (secondHalf) {  // Continue until the end of the reversed second half
            if (firstHalf->val != secondHalf->val) {
                return false;  // If values mismatch, it's not a palindrome
            }
            firstHalf = firstHalf->next;  // Move to the next node in the first half
            secondHalf = secondHalf->next;  // Move to the next node in the reversed second half
        }

        // Step 4: (Optional) Restore the second half of the list to its original order
        slow->next = reverseList(slow->next);

        return true;  // If all values matched, the list is a palindrome
    }
};