class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Initialize counters and candidate element
        int c = 0;    // Counter for the current candidate
        int ans = 0;  // Candidate for majority element

        // Iterate through each element in the vector
        for (int i = 0; i < nums.size(); i++) {
            // If counter is zero, set the current element as the new candidate
            if (c == 0)
                ans = nums[i];
            
            // If the current element matches the candidate, increment the counter
            if (nums[i] == ans) 
                c++;
            // If the current element does not match the candidate, decrement the counter
            else 
                c--;
        }

        // Return the candidate which is supposed to be the majority element
        return ans;
    }
};