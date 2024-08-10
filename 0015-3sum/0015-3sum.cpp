class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Vector to store the result triplets
        int n = nums.size(); // Size of the input array

        // Sort the array to easily manage duplicates and use two-pointer technique
        sort(nums.begin(), nums.end());

        // Iterate through the array, fixing one element at a time
        for (int i = 0; i < n-2; i++) {
            // Skip duplicate elements to avoid duplicate triplets in the result
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Initialize two pointers
            int j = i + 1; // Pointer starting from the next element
            int k = n - 1; // Pointer starting from the last element

            // Use two-pointer technique to find the other two numbers that sum to zero with nums[i]
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet

                if (sum < 0) {
                    // If the sum is less than zero, move the left pointer (j) to the right
                    j++;
                } 
                else if (sum == 0) {
                    // If the sum is zero, we've found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Move the left pointer (j) to the right, skipping duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    // Move the right pointer (k) to the left, skipping duplicates
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    // Move k to new element, beacuse k-1 is differet after completion of above loop
                    k--;
                } 
                else {
                    // If the sum is greater than zero, move the right pointer (k) to the left
                    k--;
                }
            }
        }

        return ans; // Return the list of all found triplets
    }

};