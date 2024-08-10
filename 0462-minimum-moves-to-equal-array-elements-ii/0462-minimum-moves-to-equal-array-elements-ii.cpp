class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort the array to arrange the elements in non-decreasing order.
        sort(nums.begin(), nums.end());

        // Find the median of the array, which will be our target value.
        // The median minimizes the sum of absolute differences.
        int n  = nums.size();
        int target = nums[n/2];

        // Initialize a variable to store the total number of moves.
        int ans = 0;

        // Calculate the total number of moves required to make all elements equal to the target (median).
        for(int i = 0; i < n; i++) {
            ans += abs(nums[i] - target);  // Add the difference between each element and the target.
        }

        // Return the total number of moves.
        return ans;
    }
};