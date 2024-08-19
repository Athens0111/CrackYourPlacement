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

        // If one of the lists is not exhausted, append the remaining nodes directly to the merged list
        if (end) {  // If the merged list already has some elements
            if (list1)  // If there are remaining nodes in list1, link them to the end of the merged list
                end->next = list1;
            
            if (list2)  // If there are remaining nodes in list2, link them to the end of the merged list
                end->next = list2;
        } else {  // If the merged list is empty (meaning either list1 or list2 was initially empty)
            if (list1)  // If list1 has nodes, set ans to point to list1
                ans = list1;
            
            if (list2)  // If list2 has nodes, set ans to point to list2
                ans = list2;            
        }       

        return ans;  // Return the head of the merged linked list
    }
};