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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ans = NULL, *p = head, *q = NULL;  // Initialize ans to store the new list, p to traverse the original list, q to build the new list

        while (p) {  // Traverse the entire linked list
            if (p->val != val) {  // If the current node's value is not equal to the target value
                ListNode *temp = new ListNode(p->val);  // Create a new node with the current value
                if (!ans) {  // If ans is null, it means this is the first node in the new list
                    ans = temp;  // Set ans to point to the first node of the new list
                    q = ans;  // Set q to point to the last node in the new list (currently the first and only node)
                }
                else {
                    q->next = temp;  // Link the new node to the last node in the new list
                    q = q->next;  // Move q to the new node, which is now the last node in the list
                }
            }
            p = p->next;  // Move p to the next node in the original list
        }

        return ans;  // Return the head of the new list with the target value removed
    }
};