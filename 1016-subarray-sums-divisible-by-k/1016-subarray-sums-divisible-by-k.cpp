class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0; // Initialize the count of subarrays divisible by k to 0
        int sum = 0; // Initialize the cumulative sum to 0
        map<int, int> mp; // Create a map to store the frequency of prefix sums modulo k
        mp[0]++; // There is one subarray (the empty subarray) with a sum that is divisible by k
        int n = nums.size(); // Get the size of the input array

        // Iterate through each element in the array
        for(int i = 0; i < n; i++) {
            sum += nums[i]; // Update the cumulative sum with the current element
            
            // Compute the remainder of the cumulative sum when divided by k
            int x = sum % k;
            
            // Handle negative remainders to ensure they fall within the range [0, k-1]
            if (x < 0) x += k;
            
            // Check if there is a prefix sum modulo k that matches the current remainder
            // This means that there is a subarray ending at the current index with a sum
            // that is divisible by k
            if(mp.find(x) != mp.end()){
                ans += mp[x]; // Add the number of times the same remainder has occurred
            }
            
            // Increment the frequency of the current remainder
            mp[x]++;
        }

        return ans; // Return the total count of subarrays divisible by k
    }
};