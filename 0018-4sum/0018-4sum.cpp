class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;  // This will store the final result of all quadruplets that sum up to the target
        int n = nums.size();  // Store the size of the input array

        // Sort the array to make it easier to avoid duplicates and to use two-pointer technique
        sort(nums.begin(), nums.end());

        // First loop: fix the first element of the quadruplet
        for(int i=0; i<n-3; i++){
            // Skip duplicates for the first element
            if(i>0 && nums[i] == nums[i-1])
                continue;

            // Second loop: fix the second element of the quadruplet
            for(int j=i+1; j<n-2; j++){

                // Skip duplicates for the second element
                if(j>(i+1) && nums[j] == nums[j-1]) continue;

                int k = j+1;  // Initialize the third element index
                int l = n-1;  // Initialize the fourth element index

                // Two-pointer approach to find the other two elements
                while(k < l){
                    long long sum = nums[i];  // Start with the first element

                    // Check for potential overflow when adding the second element
                    if(sum + nums[j] > INT_MAX)
                        return {{}};
                    
                    sum += nums[j];  // Add the second element
                    sum += nums[k];  // Add the third element
                    sum += nums[l];  // Add the fourth element

                    // If the sum is less than the target, move the third pointer right to increase the sum
                    if(sum < target)
                        k++;
                    // If the sum matches the target, store the quadruplet
                    else if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        l--;  // Move the fourth pointer left to check for other potential combinations
                        k++;  // Move the third pointer right to check for other potential combinations

                        // Skip duplicates for the third element
                        while(k < l && nums[k] == nums[k-1])
                            k++;

                        // Skip duplicates for the fourth element
                        while(k < l && nums[l] == nums[l+1])
                            l--;
                    }
                    // If the sum is greater than the target, move the fourth pointer left to decrease the sum
                    else
                        l--;
                }
            }
        }

        // Return the result which contains all the quadruplets that sum up to the target
        return ans;
    }

};