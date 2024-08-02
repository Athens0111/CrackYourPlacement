class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a map to store the complement of each element and its index
        map<int, int> mp;
        int n = nums.size();
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // Check if the complement (target - nums[i]) exists in the map
            if (mp.find(target - nums[i]) != mp.end()) {
                // If it exists, return the indices of the complement and the current element
                return {mp[target - nums[i]], i};
            }
            // If it doesn't exist, add the current element and its index to the map
            mp[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector
        return {};
    }
};