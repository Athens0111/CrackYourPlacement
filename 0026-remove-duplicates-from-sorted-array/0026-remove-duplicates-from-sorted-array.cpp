class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Create a temporary vector to store unique elements
        vector<int> temp;
        // Initialize a counter for unique elements and set t to the first element
        int k = 1, t = nums[0];

        // Iterate through the input vector
        for (int i = 0; i < nums.size(); i++) {
            // For the first element, add it to the temporary vector
            if (i == 0) {
                temp.push_back(nums[i]);
            } else {
                // If the current element is different from the last unique element
                if (nums[i] != t) {
                    // Update t to the current element and add it to the temporary vector
                    t = nums[i];
                    temp.push_back(t);
                    // Increment the counter for unique elements
                    k++;
                }
            }
        }
        // Replace the original vector with the temporary vector containing unique elements
        nums = temp;
        // Return the count of unique elements
        return k;
    }

};