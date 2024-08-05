class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans; // Initialize the result vector to store duplicates

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]) - 1; // Compute the index by taking the absolute value of the current element minus one

            // If the value at the computed index is negative, it means the current element is a duplicate
            if (nums[x] < 0)
                ans.push_back(x + 1); // Add the current element (x + 1) to the result vector

            nums[x] *= -1; // Negate the value at the computed index to mark it as visited
        }

        return ans; // Return the result vector containing all the duplicates
    }
};