class Solution {
public:
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