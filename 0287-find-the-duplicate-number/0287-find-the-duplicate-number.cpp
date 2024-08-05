class Solution {
public:
/*
    1st way
    int findDuplicate(vector<int>& nums) {
        int slow = 0; // Initialize slow pointer to the first index
        int fast = 0; // Initialize fast pointer to the first index

        // Phase 1: Detecting the cycle
        do {
            slow = nums[slow]; // Move slow pointer one step
            fast = nums[nums[fast]]; // Move fast pointer two steps
        } while (slow != fast); // Continue until slow and fast pointers meet

        // Phase 2: Finding the entry point of the cycle (duplicate element)
        fast = 0; // Reset fast pointer to the first index

        while (slow != fast) {
            slow = nums[slow]; // Move slow pointer one step
            fast = nums[fast]; // Move fast pointer one step
        }

        return slow; // Return the duplicate element
    }
*/

    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        int slow = n - 1; // Initialize slow pointer to the last index
        int fast = n - 1; // Initialize fast pointer to the last index

        // Phase 1: Detecting the cycle
        while (true) {
            slow = nums[slow] - 1; // Move slow pointer one step
            fast = nums[nums[fast] - 1] - 1; // Move fast pointer two steps

            if (slow == fast) // If slow and fast pointers meet, a cycle is detected
                break;
        }

        // Phase 2: Finding the entry point of the cycle (duplicate element)
        fast = n - 1; // Reset fast pointer to the last index

        while (true) {
            slow = nums[slow] - 1; // Move slow pointer one step
            fast = nums[fast] - 1; // Move fast pointer one step

            if (slow == fast) // If slow and fast pointers meet, the duplicate element is found
                return slow + 1; // Return the duplicate element (convert 0-based index to 1-based)
        }
    }
};