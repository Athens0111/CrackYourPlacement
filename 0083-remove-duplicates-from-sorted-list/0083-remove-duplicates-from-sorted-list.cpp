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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *q = head, *p = NULL;  // q is used to traverse the list, p will track the last node in the new list
        ListNode *ans = NULL;  // ans will point to the head of the new list without duplicates

        while (q) {  // Traverse the entire linked list
            if (!ans) {  // If ans is null, it means we are adding the first node to the new list
                ListNode *temp = new ListNode(q->val);  // Create a new node with the value of q
                p = temp;  // Set p to this new node
                ans = p;  // Set ans to point to the first node of the new list
            }

            if (p->val != q->val) {  // If the value of the current node q is different from the last node in the new list (p)
                ListNode *temp = new ListNode(q->val);  // Create a new node with q's value
                p->next = temp;  // Link the new node to the last node in the new list
                p = p->next;  // Move p to the new node
            }
            q = q->next;  // Move q to the next node in the original list
        }

        return ans;  // Return the head of the new list without duplicates
    }
};