class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Initialize two pointers i and j to 0
        int i = 0, j = 0;
        // Get the size of the vector
        int n = nums.size();
        
        // Loop through the vector
        for (i; i < n; i++) {
            // If the current element is not zero
            if (nums[i] != 0) {
                // Swap the current element with the element at index j
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                // Increment j to point to the next position for a non-zero element
                j++;
            }
        }
    }
};