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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = NULL, *end = NULL;  // Initialize ans to store the merged list, end to keep track of the last node in the merged list
        ListNode *p = list1;  // Pointer to traverse list1
        ListNode *q = list2;  // Pointer to traverse list2

        // Merge nodes from both lists while both lists have nodes
        while (list1 && list2) {
            ListNode *temp = NULL;  // Temporary pointer to store the current smallest node
            if (list1->val < list2->val) {
                temp = new ListNode(list1->val);  // Create a new node with the value from list1
                list1 = list1->next;  // Move to the next node in list1
            } else {
                temp = new ListNode(list2->val);  // Create a new node with the value from list2
                list2 = list2->next;  // Move to the next node in list2
            }
            
            if (!ans) {  // If ans is null, it means this is the first node being added to the merged list
                ans = temp;  // Set ans to point to the first node of the merged list
                end = ans;  // Set end to point to the last node (currently the first and only node)
            } else {
                end->next = temp;  // Link the new node to the last node in the merged list
                end = end->next;  // Move end to the new last node
            }
        }

        // Append the remaining nodes from list1 (if any)
        while (list1) {
            ListNode *temp = new ListNode(list1->val);  // Create a new node with the value from list1
            if (!ans) {
                ans = temp;
                end = ans;
            } else {
                end->next = temp;
                end = end->next;
            }
            list1 = list1->next;  // Move to the next node in list1
        }

        // Append the remaining nodes from list2 (if any)
        while (list2) {
            ListNode *temp = new ListNode(list2->val);  // Create a new node with the value from list2
            if (!ans) {
                ans = temp;
                end = ans;
            } else {
                end->next = temp;
                end = end->next;
            }
            list2 = list2->next;  // Move to the next node in list2
        }        

        return ans;  // Return the head of the merged linked list
    }
};