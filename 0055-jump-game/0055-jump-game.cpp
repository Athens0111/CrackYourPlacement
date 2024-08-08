class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize the maximum reach initially to the first element's value
        int max_reach = nums[0];
        
        // Variable to store the furthest index we can reach from the current position
        int capacity = 0;

        // Iterate through each index in the array
        for(int i = 0; i < n; i++) {
            // Update max_reach to the furthest point we can reach so far
            max_reach = max(max_reach, capacity);

            // If the maximum reach is at or beyond the last index, we can reach the end
            if(max_reach >= n - 1)
                return true;

            // If we are not at the last index and can still move forward
            if(i < max_reach && i < n - 1)
                // Calculate the new capacity (reach from the current index)
                capacity = nums[i + 1] + i + 1;
            // If we can't move beyond the current index and haven't reached the last index
            else if(i >= max_reach && i != n - 1) {
                return false; // It's not possible to reach the end
            }
        }

        // If we have iterated through the entire array, it means we can reach the end
        return true;
    }
};